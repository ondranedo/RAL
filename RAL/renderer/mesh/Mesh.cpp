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

#include "Mesh.h"

#include <utility>

namespace RAL{

    void Mesh::openRalms(const std::string& path) {
        setPath(path);
        openRalms();
    }

    std::string Mesh::getPath() {
        return m_path;
    }

    void Mesh::setPath(std::string path) {
        m_path = std::move(path);
    }

    void Mesh::openRalms() {

    }

    void Mesh::saveRalms() {

    }

    void Mesh::saveRalms(const std::string &path) {
        setPath(path);
        saveRalms();
    }

    Mesh::Mesh() = default;

    Mesh::~Mesh() = default;
}

