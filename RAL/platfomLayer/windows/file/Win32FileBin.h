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

#ifndef RAL_PROJECT_WIN32FILEBIN_H
#define RAL_PROJECT_WIN32FILEBIN_H

#ifdef RAL_WINDOWS
#include <platfomLayer/file/FileBin.h>
#include <platfomLayer/windows/file/Win32File.h>

namespace RAL::Win32{
    class Win32FileBin : public virtual FileBin, public virtual Win32File{
    public:
        Win32FileBin();
        ~Win32FileBin() override;

        size_t readInto(void *dest, size_t elementSize, size_t elementCount) override;
        size_t readInto(void *dest, size_t elementSize) override;

        void writeFrom(const void *src, size_t elementSize, size_t elementCount) override;
        void writeFrom(const void *src, size_t elementSize) override;

        void reset() const override;

    private:
        const char* getModeInFormat(Mode mode) override;
    };
}
#endif //!RAL_WINDOWS
#endif //RAL_PROJECT_WIN32FILEBIN_H
