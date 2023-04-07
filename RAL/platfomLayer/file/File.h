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


#ifndef RAL_PROJECT_FILE_H
#define RAL_PROJECT_FILE_H

#include <core/memoryManager/Overload.h>

#include <string>
#include <vector>
#include <optional>
#include <core/baseClass/BaseComponent.h>

namespace RAL {
    class File : public BaseComponent {
	public:
        enum class Mode {
            None, Read, Write, ReadWrite, Append
        };

    public:
        File();
        virtual ~File();

        virtual void open(const std::string& path, Mode mode) = 0;
        virtual void close() = 0;

        [[nodiscard]] Mode getMode() const;
        [[nodiscard]] const std::string& getPath() const;

        void init() override;

        void release() override;

        void update() override;

    protected:
        Mode m_mode;
        std::string m_path;
    };
}; // RAL

#endif //!RAL_PROJECT_FILE_H
