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
#ifndef RAL_PROJECT_OPENGL_H
#define RAL_PROJECT_OPENGL_H

#include <renderer/renderingAPI/RenderingAPI.h>

namespace RAL
{

    class GLRenderingAPI : public RenderingAPI
    {
    public:
        void init() override;
        void useDefaultProgram() override;
    private:
        void shaderInit() override;
        void compileShaders() override;
        void attachShader() override;

    protected:
        unsigned int vertexShader, fragmentShader, shaderProgram;
        const char *vertexShaderSource = "#version 460 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";

        const char *fragmentShaderSource = "#version 460 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                           "}\n\0";
    };
};
#endif //!RAL_PROJECT_OPENGL_H