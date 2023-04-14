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

namespace RAL{

    GLProgram::GLProgram() : m_programID{}, m_programAttribLayout() {}

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
            m_programAttribLayout.emplace_back(name, location);
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
}
