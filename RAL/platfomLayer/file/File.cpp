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


#include "File.h"


namespace RAL {
    File::File() : m_path(""), m_mode(Mode::None) {}
    File::~File() = default;

	File::Mode File::getMode() const
	{
		return m_mode;
	}

	const std::string& File::getPath() const {
        return m_path;
    }

    void File::init() { }
    void File::release() {}
    void File::update() { }
}