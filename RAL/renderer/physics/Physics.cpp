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

#include "Physics.h"

float RAL::PhysicalProperties::getXVel() const {
    return m_xVel;
}

float RAL::PhysicalProperties::getYVel() const {
    return m_yVel;
}

float RAL::PhysicalProperties::getZVel() const {
    return m_zVel;
}

float RAL::PhysicalProperties::getWeight() const {
    return m_weight;
}

void RAL::PhysicalProperties::setXVel(float value) {
    m_xVel = value;
}

void RAL::PhysicalProperties::setYVel(float value) {
    m_yVel = value;
}

void RAL::PhysicalProperties::setZVel(float value) {
    m_zVel = value;
}

void RAL::PhysicalProperties::setVel(float xValue, float yValue, float zValue) {
    setXVel(xValue);
    setYVel(yValue);
    setZVel(zValue);
}

void RAL::PhysicalProperties::setWeight(float value) {
    m_weight = value;
}

float RAL::PhysicalProperties::getXAcc() const {
    return m_xAcc;
}

float RAL::PhysicalProperties::getYAcc() const {
    return m_yAcc;
}

float RAL::PhysicalProperties::getZAcc() const {
    return m_zAcc;
}

void RAL::PhysicalProperties::setXAcc(float value) {
    m_xAcc = value;
}

void RAL::PhysicalProperties::setYAcc(float value) {
    m_yAcc = value;
}

void RAL::PhysicalProperties::setZAcc(float value) {
    m_zAcc = value;
}

void RAL::PhysicalProperties::setAcc(float xValue, float yValue, float zValue) {
    setXAcc(xValue);
    setYAcc(yValue);
    setZAcc(zValue);
}

void RAL::PhysicalProperties::updateXVel(float seconds) {
    setXVel(getXAcc() * seconds);
}

void RAL::PhysicalProperties::updateYVel(float seconds) {
    setYVel(getYAcc() * seconds);
}

void RAL::PhysicalProperties::updateZVel(float seconds) {
    setZVel(getZAcc() * seconds);
}

void RAL::PhysicalProperties::updateVel(float seconds) {
    updateXVel(seconds);
    updateYVel(seconds);
    updateZVel(seconds);
}

RAL::PhysicalProperties::PhysicalProperties() = default;

RAL::PhysicalProperties::~PhysicalProperties() = default;
