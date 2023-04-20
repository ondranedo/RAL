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

#include <core/memoryManager/Overload.h>
#include <renderer/renderingAPI/RenderingAPI.h>
#include <optional>
#include <array>
#include <unordered_map>
#include <renderer/renderingAPI/platform/openGL/GLProgram.h>

namespace RAL
{

    class GLRenderingAPI final : public RenderingAPI
    {
    public:
        GLRenderingAPI();
        ~GLRenderingAPI();

        void clear() override;

        void init() override;

        void release() override;

        void draw() override;

        void bind(const IndexBuffer &indexBuffer) override;

        void bind(const VertexBuffer &vertexBuffer) override;

        // Shader/Program functions
        void setProgram(uint16_t program) override;
        void compileProgram(uint16_t id, const std::string &vertex, const std::string &fragment) override;
        void sendProgramData(const ProgramData &data) override;
        void sendProgramData(const ProgramData &data, const CustomProgramData &custom_data) override;

        void sendTexture(const TextureParam& texture_id) override;

    private:
        void setWindowToDraw() override;

        void setAttributes();

        void setBindables();


    protected:
        unsigned int m_vertexArray, m_indexBuffer, m_vertexBuffer;
        uint32_t m_indicesCount;
        VertexBufferLayout m_vertexBufferLayout;

        std::unordered_map<uint16_t, GLProgram*> m_programs;
        GLProgram* m_activeProgram;
        unsigned int m_activeTexture;
    };
}
#endif //!RAL_PROJECT_GLRENDERINGAPI_H