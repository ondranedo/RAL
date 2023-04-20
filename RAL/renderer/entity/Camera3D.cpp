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

#include "Camera3D.h"

namespace RAL{

    void Camera3D::setWidth(uint16_t value) {
        m_width = value;
    }

    uint16_t Camera3D::getWidth() const {
        return m_width;
    }

    void Camera3D::setProjection(Camera3D::Projection value) {
        m_projection = value;
    }

    Camera3D::Projection Camera3D::getProjection() {
        return m_projection;
    }

    float Camera3D::getXRot() const {
        return m_xRot;
    }

    float Camera3D::getYRot() const {
        return m_yRot;
    }

    float Camera3D::getZRot() const {
        return m_zRot;
    }

    void Camera3D::setXRot(float value) {
        m_xRot = value;
    }

    void Camera3D::setYRot(float value) {
        m_yRot = value;
    }

    void Camera3D::setZRot(float value) {
        m_zRot = value;
    }

    Camera3D::~Camera3D() = default;

    Camera3D::Camera3D() : m_projection(Projection::Perspective) {}

    void Camera3D::setRot(float xValue, float yValue, float zValue) {
        setXRot(xValue);
        setYRot(yValue);
        setZRot(zValue);
    }
}