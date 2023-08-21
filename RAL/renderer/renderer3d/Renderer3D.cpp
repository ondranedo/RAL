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
#include "Renderer3D.h"
#include <vendor/glm/glm/glm.hpp>
#include <vendor/glm/glm/gtc/matrix_transform.hpp>

namespace RAL {
    Renderer3D::Renderer3D() : m_activeScene(nullptr) {}

    void Renderer3D::init() {
        std::string vertexShaderSource = "#version 460 core\n"
                                         "layout (location = 0) in vec3 positionXYZ;\n"
                                         "out vec3 ourColor;\n"
                                         "uniform mat4 MVP;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(positionXYZ, 1.0) * MVP;\n"
                                         "   ourColor = vec3(0.133f,0.35f,0.682f);\n"
                                         "}";


        std::string fragmentShaderSource = "#version 460 core\n"
                                           "out vec4 FragColor;\n"
                                           "in vec3 ourColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(ourColor, 1.0f);\n"
                                           "}\n";
        // TODO: add configurable option
        renderingAPI->clearColour(0x303338);

        // TODO: add shader archive
        renderingAPI->compileProgram(0, vertexShaderSource, fragmentShaderSource);
    }

    void Renderer3D::release() {

    }

    void Renderer3D::update() {
        // Should not be called
    }

    void Renderer3D::renderLoop() {
        RAL_ASSERTRV(m_activeScene != nullptr, "Scene is nullptr");
        RAL_ASSERTRV(renderingAPI != nullptr, "Rendering API is nullptr");

        renderingAPI->clear();
        auto camera = m_activeScene->getCamera("camera");
        auto object = m_activeScene->getObject("object");

        float vertex_data[4000];
        size_t vertex_data_size = 0;

        for(auto i = object->getMesh()->beginVertex(); i != object->getMesh()->endVertex(); i++)
        {
            vertex_data[vertex_data_size++] = (*i).x;
            vertex_data[vertex_data_size++] = (*i).y;
            vertex_data[vertex_data_size++] = (*i).z;
        }
        vertex_data_size*=sizeof(float);

        unsigned index_data[6000];
        size_t index_data_count = 0;

        for(auto i = object->getMesh()->beginTriangle(); i != object->getMesh()->endTriangle(); i++)
        {
            index_data[index_data_count++] = (*i).indexA;
            index_data[index_data_count++] = (*i).indexB;
            index_data[index_data_count++] = (*i).indexC;
        }

        VertexBuffer vb(vertex_data, vertex_data_size, VertexBufferLayout({VertexBufferLayout::Entry::POS_XYZ}));
        IndexBuffer ib(index_data, index_data_count);

        renderingAPI->setProgram(0);
        CustomProgramData data;
        float normalized = camera->getWidth()/2.0f;
        glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(-camera->getXPos(), -camera->getYPos(), -camera->getZPos()));
        View = View * glm::rotate(glm::mat4(1.0f), glm::radians(camera->getXRot()), glm::vec3(0.1f, 0.4f, 0.2f));
        glm::mat4 MVP = glm::ortho(-normalized, normalized, -normalized/WindowRatioValue(m_window->getSpec().ratio), normalized/WindowRatioValue(m_window->getSpec().ratio));
        MVP = View * MVP;
        data.addData(&MVP[0], sizeof(MVP), CustomProgramData::Type::MAT4, "MVP");
        renderingAPI->sendProgramData({}, data);

        renderingAPI->bind(ib);
        renderingAPI->bind(vb);

        renderingAPI->draw();
        m_window->swapBuffers();
    }

    void Renderer3D::setScene(Scene3D *scene) {
        if(m_activeScene == nullptr)
            m_activeScene = scene;
        else
        {
            RAL_LOG_ERROR("Scene is not nullptr");
        }
    }

    void Renderer3D::clearScene() {
        m_activeScene = nullptr;
    }
} // RAL