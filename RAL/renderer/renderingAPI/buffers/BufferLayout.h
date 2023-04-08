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
#ifndef RAL_PROJECT_BUFFERLAYOUT_H
#define RAL_PROJECT_BUFFERLAYOUT_H

#include <initializer_list>

namespace RAL
{
    class BufferLayout
    {
    public:
        enum class LayoutType
        {
            FLOAT, FLOAT2, FLOAT3, FLOAT4, INT, INT2, INT3, INT4
        };

        virtual ~BufferLayout() = default;
        BufferLayout();

        virtual void setLayout(std::initializer_list<LayoutType> layout) = 0;

        //TODO Initializer list for BufferLayout Class
        unsigned int m_normalized, m_fullLayoutSize, m_componentSize, m_offset, m_attributeIndex;
        std::initializer_list<LayoutType> m_layout;
    protected:

        virtual unsigned int getFullLayoutSize() = 0;

        virtual unsigned int getComponentSize(LayoutType element) = 0;

        virtual unsigned int getOffset() = 0;

        virtual void addVertexData() = 0;
    };
} // RAL

#endif //!RAL_PROJECT_BUFFERLAYOUT_H