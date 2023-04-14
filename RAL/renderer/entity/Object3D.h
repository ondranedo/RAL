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
        [[nodiscard]] float getXScale() const;
        [[nodiscard]] float getYScale() const;
        [[nodiscard]] float getZScale() const;
        [[nodiscard]] float getScale() const;

        void setMesh(Mesh3D* mesh);
        void setXRot(float value);
        void setYRot(float value);
        void setZRot(float value);
        void setXScale(float value);
        void setYScale(float value);
        void setZScale(float value);
        void setScale(float value);

    private:
        Mesh3D* m_mesh{};
        float m_xRot;
        float m_yRot;
        float m_zRot;
        float m_xScale;
        float m_yScale;
        float m_zScale;
    };
}

#endif //RAL_PROJECT_OBJECT3D_H
