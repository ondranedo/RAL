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
#ifndef RAL_PROJECT_ENTITY_H
#define RAL_PROJECT_ENTITY_H

#include <string>

namespace RAL {
    class Entity {
    public:
        Entity();
        ~Entity();

        [[nodiscard]] float getXPos() const;
        [[nodiscard]] float getYPos() const;
        std::string getName();

        void setXPos(float value);
        void setYPos(float value);
        void setPos(float xValue, float yValue);
        void setName(std::string name);

    protected:
        std::string m_name;
        float m_xPos{};
        float m_yPos{};
    };
} // RAL

#endif //!RAL_PROJECT_ENTITY_H
