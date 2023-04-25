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
#ifndef RAL_PROJECT_RENDERER3D_H
#define RAL_PROJECT_RENDERER3D_H

#include <renderer/Renderer.h>
#include <renderer/scene/Scene3D.h>

namespace RAL {

    class Renderer3D : public Renderer {
    public:
        void init() override;
        void release() override;
        void update() override;
        void renderLoop() override;
        void setScene(Scene3D* scene);
        void clearScene();
    private:
        Scene3D* m_activeScene;
    };

} // RAL

#endif //RAL_PROJECT_RENDERER3D_H
