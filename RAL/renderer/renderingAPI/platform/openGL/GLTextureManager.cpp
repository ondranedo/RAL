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
#include "GLTextureManager.h"
#include "core/utility/Logger.h"

#include <vendor/glad/gl_4.0_core_debug/include/glad/gl.h>

namespace RAL
{
    void GLTextureManager::init()
    {
        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &m_MaxTextureUnitCount);
    }

    void GLTextureManager::generate(uint16_t id)
    {
        glGenTextures(1, &m_id);
        GLenum error = glGetError();
        if(error != GL_NO_ERROR)
        {
            //TODO Second chance
            release();
        }
        activatedTextures[id] = m_id;
    }

    void GLTextureManager::release()
    {
        for (auto &[key, value]: activatedTextures)
        {
            glDeleteTextures(1, &value);
        }
    }

    void GLTextureManager::bind(GLint type, const std::vector<unsigned int> &IDsToBind)
    {
        if (m_MaxTextureUnitCount < IDsToBind.size())
        {
            RAL_LOG_WARNING("Vector IDsToBind contains more IDs that is allowed. Max value %d, Actual size %d",
                          m_MaxTextureUnitCount, IDsToBind.size());
        }
        for (auto &ID: IDsToBind)
        {
            glActiveTexture(GL_TEXTURE0 + m_TextureUnitID);
            m_TextureUnitID++;
            glBindTexture(type, activatedTextures[ID]);
        }
        m_TextureUnitID = 0;
    }

    void GLTextureManager::bind(GLint type) const
    {
        glBindTexture(type, m_id);
    }

    void GLTextureManager::sendTexture(void *adr, uint16_t width, uint16_t height, uint16_t depth, uint8_t channels,
                                       uint16_t id, WrappingParam wrappingParam,
                                       FilteringParam filteringParam,
                                       DimensionsType type)
    {
        generate(id);

        auto getFormat = [](uint8_t channels) -> GLenum
        {
            return (channels == 1) ? GL_RED : (channels == 2) ? GL_RG : (channels == 3) ? GL_RGB : GL_RGBA;
        };

        auto getWrapParam = [](WrappingParam wrapParam) -> GLint
        {
            return wrapParam == WrappingParam::REPEAT ? GL_REPEAT : wrapParam ==
                                                                    WrappingParam::MIRRORED_REPEAT
                                                                    ? GL_MIRRORED_REPEAT : GL_CLAMP_TO_EDGE;
        };

        auto getFilterParam = [](FilteringParam filterParam) -> GLint
        {
            return filterParam == FilteringParam::LINEAR ? GL_LINEAR : filterParam ==
                                                                       FilteringParam::LINEAR_MIPMAP_LINEAR
                                                                       ? GL_LINEAR_MIPMAP_LINEAR :
                                                                       filterParam ==
                                                                       FilteringParam::LINEAR_MIPMAP_NEAREST
                                                                       ? GL_LINEAR_MIPMAP_NEAREST :
                                                                       filterParam ==
                                                                       FilteringParam::NEAREST
                                                                       ? GL_NEAREST :
                                                                       filterParam ==
                                                                       FilteringParam::NEAREST_MIPMAP_LINEAR
                                                                       ? GL_NEAREST_MIPMAP_LINEAR :
                                                                       filterParam ==
                                                                       FilteringParam::NEAREST_MIPMAP_NEAREST
                                                                       ? GL_NEAREST_MIPMAP_NEAREST
                                                                       : GL_NEAREST_MIPMAP_LINEAR;
        };

        auto texParamMinMag = [&](GLint dimension)
        {
            glTexParameteri(dimension, GL_TEXTURE_MIN_FILTER, getFilterParam(filteringParam));
            glTexParameteri(dimension, GL_TEXTURE_MAG_FILTER, getFilterParam(filteringParam));
        };

        auto texParamWrapper = [&](GLint d)
        {
            GLint str[3] = {GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_R};
            int r = d == GL_TEXTURE_1D ? 1 : d == GL_TEXTURE_2D ? 2 : 3;
            for (int i = 0; i < r; i++)
            {
                glTexParameteri(d, str[i], getWrapParam(wrappingParam));
            }
        };

        auto texData = [&](GLint d) -> void
        {
            switch (d)
            {
                case GL_TEXTURE_1D:
                    glTexImage1D(d, 0, static_cast<GLint>(getFormat(channels)), width, 0, getFormat(channels),
                                 GL_UNSIGNED_BYTE, adr);
                    break;
                case GL_TEXTURE_2D:
                    glTexImage2D(d, 0, static_cast<GLint>(getFormat(channels)), width, height, 0, getFormat(channels),
                                 GL_UNSIGNED_BYTE, adr);
                    break;
                case GL_TEXTURE_3D:
                    glTexImage3D(d, 0, static_cast<GLint>(getFormat(channels)), width, height, depth, 0,
                                 getFormat(channels), GL_UNSIGNED_BYTE, adr);
                    break;
            }
        };

        auto tex = [&](GLint d)
        {
            bind(d);
            texParamWrapper(d);
            texParamMinMag(d);
            texData(d);
            glGenerateMipmap(d);
        };

        tex(type == DimensionsType::_1D ? GL_TEXTURE_1D ? type == DimensionsType::_2D : GL_TEXTURE_2D
                                        : GL_TEXTURE_3D);
    }


} // RAL