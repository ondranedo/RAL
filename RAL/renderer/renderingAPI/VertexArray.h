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
#ifndef RAL_PROJECT_VERTEXARRAY_H
#define RAL_PROJECT_VERTEXARRAY_H

namespace RAL
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() {}

        virtual void bindVA() = 0;

        virtual void unbindVA() = 0;

        virtual void setLayout() = 0;
    };
};

#endif //!RAL_PROJECT_VERTEXARRAY_H