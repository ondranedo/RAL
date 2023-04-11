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
#ifndef RAL_PROJECT_INDEXBUFFER_H
#define RAL_PROJECT_INDEXBUFFER_H

#include <renderer/renderingAPI/buffers/Buffer.h>

namespace RAL
{
    class IndexBuffer : public virtual Buffer
    {
    public:
        virtual ~IndexBuffer();
        virtual void setData(unsigned int *ptr, unsigned int count);

    private:
    };
} // RAL

#endif //!RAL_PROJECT_INDEXBUFFER_H
