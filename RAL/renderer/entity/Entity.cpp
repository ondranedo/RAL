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

#include "Entity.h"

#include <utility>

namespace RAL{

    Entity::Entity() = default;

    Entity::~Entity() = default;

    int32_t Entity::getXPos() const {
        return m_xPos;
    }

    int32_t Entity::getYPos() const {
        return m_yPos;
    }

    std::string Entity::getName() {
        return m_name;
    }

    void Entity::setXPos(int32_t value) {
        m_xPos = value;
    }

    void Entity::setYPos(int32_t value) {
        m_yPos = value;
    }

    void Entity::setName(std::string name) {
        m_name = std::move(name);
    }

    void Entity::setPos(int32_t xValue, int32_t yValue) {
        setXPos(xValue);
        setYPos(yValue);
    }
}
