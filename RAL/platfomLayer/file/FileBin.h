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

#ifndef RAL_PROJECT_FILEBIN_H
#define RAL_PROJECT_FILEBIN_H

#include <platfomLayer/file/File.h>

namespace RAL{
    class FileBin : public virtual File{
    public:
        virtual ~FileBin();

        virtual size_t readInto(void *dest, size_t elementSize, size_t elementCount) = 0;
        virtual size_t readInto(void *dest, size_t elementSize) = 0;

        virtual void writeFrom(const void *src, size_t elementSize, size_t elementCount) = 0;
        virtual void writeFrom(const void *src, size_t elementSize) = 0;

        virtual void reset() const = 0;
    };


}

#endif //RAL_PROJECT_FILEBIN_H
