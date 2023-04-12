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
#ifndef RAL_PROJECT_GLRENDERINGAPI_H
#define RAL_PROJECT_GLRENDERINGAPI_H

#include <renderer/renderingAPI/RenderingAPI.h>

namespace RAL
{

    class GLRenderingAPI : public RenderingAPI
    {
    public:
        void clear() override;

        void clearColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

        void init() override;

        void release() override;

        void draw() override;

        void bind(const IndexBuffer &indexBuffer) override;

        void bind(const VertexBuffer &vertexBuffer) override;

        void unbind(const IndexBuffer &indexBuffer) override;

        void unbind(const VertexBuffer &vertexBuffer) override;
    protected:
        unsigned int m_VA, m_IB, m_VB;
        uint32_t m_indiciesCount;
        bool m_isVBDataSet, m_isIBDataSet;
    };
}
#endif //!RAL_PROJECT_GLRENDERINGAPI_H