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
#include <renderer/renderingAPI/TextureParam.h>
namespace RAL
{
    class GLTextureManager
    {
    public:
        GLTextureManager();

        // Stores array of textures to VRAM, if texture is already stored, it will not be stored again
        void store(const std::vector<TextureParam>& textures_to_store);

        // Stores textures to VRAM, if texture is already stored, it will not be stored again
        void store(const TextureParam& texture_to_store);

        void init();

    private:
        // stores all activated textures, if we want to send texture to GPU,
        // we need to check if it is already activated
        // [texture_id] -> [gl_texture_unit]
        std::unordered_map<uint32_t, uint32_t> m_activatedTextures;

        // Maximum number of texture units that can be used at once
        uint32_t m_maxTextureUnitCount;
    };

} // RAL

#endif //!RAL_PROJECT_GLTEXTUREMANAGER_H