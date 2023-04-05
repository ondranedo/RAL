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


#include <renderer/renderingAPI/VertexArray.h>

namespace RAL
{
    class GLVertexArray : public VertexArray
    {
    public:
        ~GLVertexArray() override;

        GLVertexArray();

        void bindVA() override;

        void unbindVA() override;

        void setLayout() override;

    protected:
        unsigned int m_VA{};
    };
};
#endif //!RAL_PROJECT_GLVERTEXARRAY_H