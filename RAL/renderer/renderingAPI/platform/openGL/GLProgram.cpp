/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#include "GLProgram.h"

#include <vendor/glad/gl_4.0_core_debug/include/glad/gl.h>
#include <core/utility/Logger.h>
#include <renderer/renderingAPI/buffers/VertexBufferLayout.h>
#include <renderer/renderingAPI/platform/openGL/GLTypes.h>

namespace RAL{

    GLProgram::GLProgram() : m_programID{}, m_programAttribLayout{},m_textureUnit{},m_isTextureUVset(false) {}

    GLProgram::~GLProgram() {
        if(m_programID.has_value())
            glDeleteProgram(m_programID.value());
    }

    bool GLProgram::compile(const std::string &vertex, const std::string &fragment) {
        // Shader compilation
        unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

        auto _ = [](unsigned int shader, char* src, const std::string& type) {
            glShaderSource(shader, 1, &src, nullptr);
            glCompileShader(shader);
            int result;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
            if(result != GL_TRUE) {
                GLsizei log_length = 0;
                char message[1024];
                glGetShaderInfoLog(shader, 1024, &log_length, message);
                RAL_LOG_ERROR("Failed to compile %s: %s",type.c_str(), message);
                return false;
            }
            return true;
        };

        _(vs, const_cast<char*>(vertex.c_str()), "vertex shader");
        _(fs, const_cast<char*>(fragment.c_str()), "fragment shader");

        // Program compilation - linking shaders to a program
        unsigned int program = glCreateProgram();

        glAttachShader(program, vs);
        glAttachShader(program, fs);

        glLinkProgram(program);

        int result;
        glGetProgramiv(program, GL_LINK_STATUS, &result);
        if (result != GL_TRUE)
        {
            GLsizei log_length = 0;
            char message[1024];
            glGetProgramInfoLog(program, 1024, &log_length, message);
            RAL_LOG_ERROR("Failed to link program: %s", message);
            return false;
        }

        glDeleteShader(vs);
        glDeleteShader(fs);

        // store information about program layout
        int numAttribs;
        glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &numAttribs);
        for(GLuint i = 0; i < numAttribs; ++i)
        {
            char name[256];
            int name_len = -1, num = -1;
            GLenum type = GL_ZERO;
            glGetActiveAttrib(program, i, sizeof(name)-1,
                              &name_len, &num, &type, name);
            name[name_len] = 0;
            int location = glGetAttribLocation(program, name);
            // TODO: Important for shader documentation, add support for other texture types
            if(std::string(name) == VertexBufferLayout::EntryTypeToString(VertexBufferLayout::Entry::TEXTURE_UV))
                m_isTextureUVset = true;
            m_programAttribLayout.emplace_back(name, location);
        }


        // store information about program uniforms
        int numUniforms;
        glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numUniforms);
        for(GLuint i = 0; i < numUniforms; ++i)
        {
            char name[256];
            int name_len = -1, num = -1;
            GLenum type = GL_ZERO;
            glGetActiveUniform(program, i, sizeof(name)-1,
                              &name_len, &num, &type, name);
            name[name_len] = 0;
            int location = glGetUniformLocation(program, name);
            // TODO: add support for other texture types
            if(std::string(name) == "texture")
                m_textureUnit = location;
            else
                m_programUniforms[name] = {getDataTypeFromGLType(type), location};
        }

        m_programID = program;

        return true;
    }

    void GLProgram::setActive() {
        if(!m_programID.has_value())
        {
            RAL_LOG_ERROR("GL Program is not compiled yet!");
            return;
        }
        glUseProgram(m_programID.value());
    }

    int GLProgram::getAttribLocation(const std::string &name) {
        int index;
        for(auto& attrib : m_programAttribLayout)
            if(attrib.first == name)
                return attrib.second;

        RAL_LOG_FATAL("Cannot find attribute %s in GL program %d, thus can't draw", name.c_str(), m_programID);
        return -1;
    }

    void GLProgram::sendData(void *data, size_t size, CustomProgramData::Type type, const std::string &name) {
        if(!m_programID.has_value()) {
            RAL_LOG_ERROR("GL Program is not compiled yet!");
            return;
        }
        if(m_programUniforms.find(name) == m_programUniforms.end()) {
            RAL_LOG_ERROR("Cannot find uniform %s in GL program %d, thus can't send data", name.c_str(), m_programID);
            return;
        }
        auto uniform = m_programUniforms[name];

        if(uniform.first != type){
            RAL_LOG_ERROR("Uniform %s in GL program %d has different type than the data being sent", name.c_str(), m_programID);
            return;
        }

        if(CustomProgramData::typeSize(uniform.first) != size){
            RAL_LOG_ERROR("Uniform %s in GL program %d has different size than the data being sent", name.c_str(), m_programID);
            return;
        }

        switch(type) {
            case CustomProgramData::Type::FLOAT: glUniform1f(uniform.second, *static_cast<float*>(data)); break;
            case CustomProgramData::Type::VEC2:  glUniform2fv(uniform.second, 1, static_cast<float*>(data)); break;
            case CustomProgramData::Type::VEC3:  glUniform3fv(uniform.second, 1, static_cast<float*>(data)); break;
            case CustomProgramData::Type::VEC4:  glUniform4fv(uniform.second, 1, static_cast<float*>(data)); break;
            case CustomProgramData::Type::BOOL:
            case CustomProgramData::Type::SAMPLER2D:
            case CustomProgramData::Type::INT:   glUniform1i(uniform.second, *static_cast<int*>(data)); break;
            case CustomProgramData::Type::MAT4:  glUniformMatrix4fv(uniform.second, 1, GL_FALSE, static_cast<float*>(data)); break;
            case CustomProgramData::Type::UINT:  glUniform1ui(uniform.second, *static_cast<unsigned int*>(data)); break;
            case CustomProgramData::Type::UVEC2: glUniform2uiv(uniform.second, 1, static_cast<unsigned int*>(data)); break;
            case CustomProgramData::Type::UVEC3: glUniform3uiv(uniform.second, 1, static_cast<unsigned int*>(data)); break;
            case CustomProgramData::Type::UVEC4: glUniform4uiv(uniform.second, 1, static_cast<unsigned int*>(data)); break;
            default:
                RAL_LOG_ERROR("Unknown uniform data type when sending data to GL program %d", m_programID);
        }
    }

    CustomProgramData::Type GLProgram::getDataTypeFromGLType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return CustomProgramData::Type::FLOAT;
            case GL_FLOAT_VEC2: return CustomProgramData::Type::VEC2;
            case GL_FLOAT_VEC3: return CustomProgramData::Type::VEC3;
            case GL_FLOAT_VEC4: return CustomProgramData::Type::VEC4;
            case GL_INT: return CustomProgramData::Type::INT;
            case GL_UNSIGNED_INT: return CustomProgramData::Type::UINT;
            case GL_UNSIGNED_INT_VEC2: return CustomProgramData::Type::UVEC2;
            case GL_UNSIGNED_INT_VEC3: return CustomProgramData::Type::UVEC3;
            case GL_UNSIGNED_INT_VEC4: return CustomProgramData::Type::UVEC4;
            case GL_BOOL: return CustomProgramData::Type::BOOL;
            case GL_FLOAT_MAT4: return CustomProgramData::Type::MAT4;
            case GL_SAMPLER_2D: return CustomProgramData::Type::SAMPLER2D;
        }
        RAL_LOG_ERROR("Unknown GL type %d, when converting GL Type to CustomProgramData::Type", type);
        return CustomProgramData::Type::UNKNOWN;
    }
#ifdef  RAL_DEBUG
    void GLProgram::printUniformLayout() {
        RAL_LOG_WARNING("Uniforms in GL program %d:", m_programID);
        for(auto& uniform : m_programUniforms)
            RAL_LOG_DEBUG("\t%s\t-> %s", uniform.first.c_str(), CustomProgramData::typeToString(uniform.second.first).c_str());
    }

    void GLProgram::printAttribLayout() {
        RAL_LOG_WARNING("Attributes in GL program %d:", m_programID);
        for(auto& attrib : m_programAttribLayout)
            RAL_LOG_DEBUG("\t%s\t-> location:%d", attrib.first.c_str(), attrib.second);
    }

    bool GLProgram::isForTextures() const {
        return m_textureUnit.has_value() && m_isTextureUVset ? true : false;
    }

#endif
}
