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
#include <renderer/renderingAPI/buffers/BufferLayout.h>

namespace RAL
{
    class GLVertexArray final : public virtual BufferLayout, public virtual GLIndexable
    {
    public:
        ~GLVertexArray() override;

        GLVertexArray();

        void bind() const;

        void unbind() const;

        void setLayout(std::initializer_list<LayoutType> layout) override;

    protected:
        typedef unsigned int GLenum;
        GLenum getGLDataType(LayoutType element);

        unsigned int getComponentSize(LayoutType element) override;

        unsigned int getFullLayoutSize() override;

        void addVertexData() override;

        unsigned int getOffset() override;

    private:
        bool firstCall = true;
    };
};
#endif //!RAL_PROJECT_GLVERTEXARRAY_H