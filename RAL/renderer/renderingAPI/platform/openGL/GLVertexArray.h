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
#ifndef RAL_PROJECT_GLVERTEXARRAY_H
#define RAL_PROJECT_GLVERTEXARRAY_H

#include <renderer/renderingAPI/platform/openGL/GLIndexable.h>

namespace RAL
{
    class GLVertexArray final: public virtual GLIndexable
    {
    public:
        ~GLVertexArray() override;

        GLVertexArray();

        void bind() const;

        void unbind() const;

        void setLayout();

    };
};
#endif //!RAL_PROJECT_GLVERTEXARRAY_H