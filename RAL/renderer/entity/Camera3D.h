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

#ifndef RAL_PROJECT_CAMERA3D_H
#define RAL_PROJECT_CAMERA3D_H

#include "Entity3D.h"

namespace RAL{
    class Camera3D: public Entity3D{
    public:
        enum class Projection{
            Perspective, Orthographic, Oblique
        };

        Camera3D();
        ~Camera3D();

        void setWidth(uint16_t value);
        void setProjection(Projection value);
        void setXRot(float value);
        void setYRot(float value);
        void setZRot(float value);
        void setRot(float xValue, float yValue, float zValue);

        [[nodiscard]] uint16_t getWidth() const;
        Projection getProjection();
        [[nodiscard]] float getXRot() const;
        [[nodiscard]] float getYRot() const;
        [[nodiscard]] float getZRot() const;

    private:
        uint16_t m_width{};
        Projection m_projection;
        float m_xRot{};
        float m_yRot{};
        float m_zRot{};
    };
}

#endif //RAL_PROJECT_CAMERA3D_H
