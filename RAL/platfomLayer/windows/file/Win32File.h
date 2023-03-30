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


#ifndef RAL_PROJECT_WIN32FILE_H
#define RAL_PROJECT_WIN32FILE_H

#include <platfomLayer/file/File.h>

namespace RAL::Win32 {
    class Win32File : public virtual File {
    public:
        Win32File();
        virtual ~Win32File();

        void open(const std::string &path, Mode mode) override;
        void close() override;

        virtual const char * getModeInFormat(Mode mode) = 0;

    protected:
        FILE* m_file;
    };
} // RAL

#endif //!RAL_PROJECT_WIN32FILE_H
