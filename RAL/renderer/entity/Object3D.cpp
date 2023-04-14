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

#include "Object3D.h"

namespace RAL{


    Object3D::Object3D() = default;

    Object3D::~Object3D() = default;

    Mesh3D *Object3D::getMesh() {
        return m_mesh;
    }

    void Object3D::setMesh(Mesh3D *mesh) {
        m_mesh = mesh;
    }

    float Object3D::getXRot() const {
        return m_xRot;
    }

    float Object3D::getYRot() const {
        return m_yRot;
    }

    float Object3D::getZRot() const {
        return m_zRot;
    }

    float Object3D::getXScale() const {
        return m_xScale;
    }

    float Object3D::getYScale() const {
        return m_yScale;
    }

    float Object3D::getZScale() const {
        return m_zScale;
    }

    void Object3D::setXRot(float value) {
        m_xRot = value;
    }

    void Object3D::setYRot(float value) {
        m_yRot = value;
    }

    void Object3D::setZRot(float value) {
        m_zRot = value;
    }

    void Object3D::setXScale(float value) {
        m_xScale = value;
    }

    void Object3D::setYScale(float value) {
        m_yScale = value;
    }

    void Object3D::setZScale(float value) {
        m_zScale = value;
    }

    void Object3D::setScale(float value) {
        setXScale(value);
        setYScale(value);
        setZScale(value);
    }

    float Object3D::getScale() const {
        return (getXScale() + getYScale() + getZScale())/3;
    }
}