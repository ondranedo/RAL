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
#ifndef RAL_PROJECT_RENDERER2D_H
#define RAL_PROJECT_RENDERER2D_H

#include <vector>

#include <renderer/Renderer.h>
#include <renderer/renderingAPI/platform/OpenGL/GLVertexArray.h>
#include <renderer/renderingAPI/platform/openGL/GLVertexBuffer.h>
#include <renderer/renderingAPI/platform/openGL/GLIndexBuffer.h>

namespace RAL {
    class Renderer2D : public Renderer {
    public:
        Renderer2D();
        void renderLoop() override;
        void addData(VertexBuffer *vertex, IndexBuffer* index) override;

        void init() override;
        void release() override;

        void update() override;

    private:
        //std::vector<VertexBuffer*> m_vertexBuffers;
        //std::vector<IndexBuffer*> m_indexBuffers;
        GLVertexArray* m_vertexArray;
        GLVertexBuffer* m_vertexBuffer;
        GLIndexBuffer* m_indexBuffer;
    };
} // RAL

#endif //RAL_PROJECT_RENDERER2D_H
