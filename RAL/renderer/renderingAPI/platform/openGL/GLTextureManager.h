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
#ifndef RAL_PROJECT_GLTEXTUREMANAGER_H
#define RAL_PROJECT_GLTEXTUREMANAGER_H

#include <core/memoryManager/Overload.h>

#include <cstdint>
#include <unordered_map>
#include <vector>

namespace RAL
{
    enum class DimensionsType : unsigned char
    {
        _1D,
        _2D,
        _3D
    };

    enum class WrappingParam : unsigned char
    {
        REPEAT,
        MIRRORED_REPEAT,
        CLAMP_TO_EDGE
    };

    enum class FilteringParam : unsigned char
    {
        NEAREST,
        LINEAR,
        NEAREST_MIPMAP_NEAREST,
        NEAREST_MIPMAP_LINEAR,
        LINEAR_MIPMAP_NEAREST,
        LINEAR_MIPMAP_LINEAR
    };

    class GLTextureManager
    {
    public:
        void init();

        void generate(uint16_t id);

        void release();

        void bind(int type,const std::vector<unsigned int>& IDsToBind);

        void sendTexture(void *adr, uint16_t width, uint16_t height, uint16_t depth, uint8_t channels, uint16_t id,
                         WrappingParam wrappingParam, FilteringParam filteringParam, DimensionsType type);

    private:
        void bind(int type) const;
        uint32_t m_id,m_TextureUnitID=0;
        int m_MaxTextureUnitCount;
        std::unordered_map<uint32_t, uint32_t> activatedTextures;
    };

} // RAL

#endif //!RAL_PROJECT_GLTEXTUREMANAGER_H