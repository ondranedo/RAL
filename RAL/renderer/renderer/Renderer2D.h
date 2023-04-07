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
#ifndef RAL_PROJECT_RENDERER2D_H
#define RAL_PROJECT_RENDERER2D_H

#include <vector>

#include <platfomLayer/window/Window.h>

namespace RAL {
    class Renderer2D {
    private:
        struct Data
        {
            std::vector<std::pair<float,float>> vertecies;
            std::vector<unsigned int> indecies;
        };
        Data m_Data;
        Window* m_Window = nullptr;

        void setWindow(Window* window);
        void setData();
    public:
        void render();
        void renderLoop();
    };
} // RAL

#endif //RAL_PROJECT_RENDERER2D_H