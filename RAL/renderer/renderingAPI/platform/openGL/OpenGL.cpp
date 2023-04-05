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
#include "OpenGL.h"
#include "core/utility/Logger.h"

#include <vendor/glad/include/glad/glad.h>

namespace RAL {
    //Default shader program
	void GLRenderingAPI::init()
	{
        shaderInit();
        compileShaders();
        attachShader();
	}

    void GLRenderingAPI::shaderInit()
    {
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        shaderProgram = glCreateProgram();
    }

    void GLRenderingAPI::compileShaders()
    {
        glShaderSource(vertexShader,1,&vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        glShaderSource(fragmentShader,1,&fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
    }

    void GLRenderingAPI::attachShader()
    {
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram,fragmentShader);
        glLinkProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }


    void GLRenderingAPI::useDefaultProgram()
    {
        glUseProgram(shaderProgram);
    }
};