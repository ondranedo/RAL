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
#include "FCM.h"
#include <core/utility/Asserts.h>

namespace RAL {
    FCM::FCM() : m_components({}), m_factories({}) {
        RAL_LOG_DEBUG("FCM created");
    }

    FCM::~FCM() {
        if(!m_components.empty())
        {
            RAL_LOG_WARNING("FCM destroyed with components still attached");
            clearComponents();
        }
        if(!m_factories.empty()) {
            RAL_LOG_WARNING("FCM destroyed with factories still attached");
            clearFactories();
        }
        RAL_LOG_DEBUG("FCM destroyed");
    }

#ifdef RAL_DEBUG
    void FCM::printComponents() {
        RAL_LOG_WARNING("FCM Components:");
        for(auto &component : m_components)
            RAL_LOG_DEBUG("\t%s\t[init:%s]\t[released:%s]", component.name.c_str(), component.wasInitialized ? "true" : "false", component.wasReleased ? "true" : "false");
    }

    void FCM::printFactories() {
        RAL_LOG_WARNING("FCM Factories:");
        char buffer[512];
        for(auto &factory : m_factories)
        {
            if(factory.ptr->getMaxObjectCount() == 0)
                snprintf(buffer, 256, "unlimited");
            else
                snprintf(buffer, 256, "%d", factory.ptr->getMaxObjectCount());
            RAL_LOG_DEBUG("\t%s\t[def.create:%s] [obj.:%d] [max.obj.:%s]", factory.typeIndex.name(), factory.defaultCreate ? "true" : "false", factory.ptr->getObjectCount(), buffer);
            size_t written = 0;
            for(auto &product : factory.products)
                written += snprintf(buffer + written, 256 - written, "%s ", product.c_str());
            RAL_LOG_DEBUG("\t\tProducts: %s", buffer);
        }
    }
#endif //~RAL_DEBUG


    void FCM::removeComponent(const std::string &name) {
        for(size_t i = 0; i < m_components.size(); i++)
        {
            if(m_components[i].name == name)
            {
                if(!m_components[i].wasReleased)
                    m_components[i].ptr->release();
                m_components[i].motherFactory->ptr->destroy(m_components[i].ptr);
                RAL_LOG_DEBUG("Removed component: ", name.c_str());
                m_components.erase(m_components.begin() + i);
                return;
            }
        }
    }

    void FCM::createComponents() {
#ifdef RAL_DEBUG
        size_t count = 0;
#endif
        for(auto &factory : m_factories) {
            if(!factory.defaultCreate) continue;
            Component com;
            auto fcomponent = factory.ptr->create();
            com.motherFactory = &factory;
            com.name = factory.ptr->productName();
            com.ptr = fcomponent;
            com.wasInitialized = false;
            com.wasReleased = false;
            factory.products.push_back(com.name);
            factory.defaultCreate = false;
            m_components.push_back(com);
#ifdef RAL_DEBUG
            count++;
#endif
        }
        if(count)
        RAL_LOG_INFO("Created %llu component%s", count, count > 1 ? "s" : "");
    }

    void FCM::initComponents() {
#ifdef RAL_DEBUG
        size_t count = 0;
#endif
        for(auto &component : m_components)
        {
            if(!component.wasInitialized)
            {
                component.ptr->init();
#ifdef RAL_DEBUG
                count++;
#endif
            }
            component.wasInitialized = true;
        }
        if(count)
        RAL_LOG_DEBUG("Initialized %llu component%s", count, count > 1 ? "s" : "");
    }

    void FCM::releaseComponents() {
#ifdef RAL_DEBUG
        size_t count = 0;
#endif
        for(auto &component : m_components)
        {
            if(!component.wasReleased)
            {
                component.ptr->init();
#ifdef RAL_DEBUG
                count++;
#endif
            }
            component.wasReleased = true;
        }
        if(count)
        RAL_LOG_DEBUG("Released %llu component%s", count, count > 1 ? "s" : "");
    }

    void FCM::updateComponents() {
        for(auto &component : m_components)
            component.ptr->update();
    }

    void FCM::clearComponents() {
        releaseComponents();
        for(auto &component : m_components)
            component.motherFactory->ptr->destroy(component.ptr);

        m_components.clear();
    }

    void FCM::clearFactories() {
        clearComponents();
        for(auto &factory : m_factories)
            delete factory.ptr;

        m_factories.clear();
    }
} // RAL
