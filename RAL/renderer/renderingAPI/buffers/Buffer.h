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
#ifndef RAL_PROJECT_BUFFER_H
#define RAL_PROJECT_BUFFER_H

namespace RAL
{
    class Buffer
    {
    public:
        /**
            1: VOLATILE = Data is set only once and used by the GPU few times.
            2: STATIC = Data is set only once and used many times.
            3: DYNAMIC = Data is changed a lot and used many times.
        */
        Buffer();
        virtual ~Buffer();

        enum class DrawUsage : unsigned char
        {
            STATIC,
            DYNAMIC,
            VOLATILE
        };

        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        void setDrawUsage(DrawUsage usage);
        DrawUsage getDrawUsage() const;

    protected:
        DrawUsage m_usage;
    };

} // RAL

#endif //!RAL_PROJECT_BUFFER_H
