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

#ifndef RAL_PROJECT_OBJECT3D_H
#define RAL_PROJECT_OBJECT3D_H

#include "Entity3D.h"
#include "../mesh/Mesh3D.h"

namespace RAL{
    class Object3D : public Entity3D{
    public:
        Object3D();
        ~Object3D();

    private:
        Mesh3D* m_mesh;
    };
}

#endif //RAL_PROJECT_OBJECT3D_H
