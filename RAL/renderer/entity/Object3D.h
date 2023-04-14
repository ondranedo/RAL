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

        Mesh3D* getMesh();
        [[nodiscard]] float getXRot() const;
        [[nodiscard]] float getYRot() const;
        [[nodiscard]] float getZRot() const;
        [[nodiscard]] float getXBoxScale() const;
        [[nodiscard]] float getYBoxScale() const;
        [[nodiscard]] float getZBoxScale() const;

        void setMesh(Mesh3D* mesh);
        void setXRot(float value);
        void setYRot(float value);
        void setZRot(float value);
        void setRot(float xValue, float yValue, float zValue);
        void setXBoxScale(float value);
        void setYBoxScale(float value);
        void setZBoxScale(float value);
        void setBoxScale(float xValue, float yValue, float zValue);

    private:
        Mesh3D* m_mesh{};
        float m_xRot;
        float m_yRot;
        float m_zRot;
        float m_xBoxScale;
        float m_yBoxScale;
        float m_zBoxScale;
    };
}

#endif //RAL_PROJECT_OBJECT3D_H
