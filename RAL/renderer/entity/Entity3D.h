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
#ifndef RAL_PROJECT_ENTITY3D_H
#define RAL_PROJECT_ENTITY3D_H

#include "Entity.h"

namespace RAL {
    class Entity3D : public Entity {
    public:
        Entity3D();
        ~Entity3D();

    private:
        int32_t m_zPos;
    };
} // RAL

#endif //!RAL_PROJECT_ENTITY3D_H
