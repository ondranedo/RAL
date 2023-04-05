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
#ifndef RAL_PROJECT_RENDERINGAPI_H
#define RAL_PROJECT_RENDERINGAPI_H
//TODO: Factory
namespace RAL {
    class RenderingAPI {
    public:
        RenderingAPI() = default;
        virtual ~RenderingAPI() = default;
        virtual void init() = 0;
        //TODO: MOVE TO SHADER FILE, maybe keep default shader
        virtual void shaderInit() = 0;
        virtual void compileShaders() = 0;
        virtual void attachShader() = 0;
        virtual void useDefaultProgram() = 0;
    private:
    };
} // RAL

#endif //!RAL_PROJECT_RENDERINGAPI_H
