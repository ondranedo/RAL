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

#ifndef RAL_PROJECT_PHYSICS_H
#define RAL_PROJECT_PHYSICS_H

namespace RAL{
    class PhysicalProperties{
    public:
        PhysicalProperties();
        ~PhysicalProperties();

        [[nodiscard]] float getXVel() const;
        [[nodiscard]] float getYVel() const;
        [[nodiscard]] float getZVel() const;
        [[nodiscard]] float getWeight() const;
        [[nodiscard]] float getXAcc() const;
        [[nodiscard]] float getYAcc() const;
        [[nodiscard]] float getZAcc() const;

        void setXVel(float value);
        void setYVel(float value);
        void setZVel(float value);
        void setVel(float xValue, float yValue, float zValue);
        void setWeight(float value);
        void setXAcc(float value);
        void setYAcc(float value);
        void setZAcc(float value);
        void setAcc(float xValue, float yValue, float zValue);

        void updateXVel(float seconds);
        void updateYVel(float seconds);
        void updateZVel(float seconds);
        void updateVel(float seconds);

    private:
        float m_xVel{};
        float m_yVel{};
        float m_zVel{};
        float m_weight{};
        float m_xAcc{};
        float m_yAcc{};
        float m_zAcc{};
    };
}

#endif //RAL_PROJECT_PHYSICS_H
