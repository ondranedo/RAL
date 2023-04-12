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
#ifndef RAL_PROJECT_GLRENDERINGAPI_H
#define RAL_PROJECT_GLRENDERINGAPI_H

#include <renderer/renderingAPI/RenderingAPI.h>

namespace RAL
{

    class GLRenderingAPI : public RenderingAPI
    {

    protected:
        unsigned int vertexShader, fragmentShader, shaderProgram;
        const char *vertexShaderSource = "#version 460 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "layout (location = 1) in vec3 aColor;\n"
                                         "out vec3 ourColor;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos, 1.0);\n"
                                         "   ourColor = aColor;\n"
                                         "}\0";


        const char *fragmentShaderSource = "#version 460 core\n"
                                           "out vec4 FragColor;\n"
                                           "in vec3 ourColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(ourColor, 1.0f);\n"
                                           "}\n\0";
    };
};
#endif //!RAL_PROJECT_GLRENDERINGAPI_H