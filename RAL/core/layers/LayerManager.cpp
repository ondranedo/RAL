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
#include "LayerManager.h"

#include <core/utility/Logger.h>

namespace RAL {
    void LayerManager::init() {
    }

    void LayerManager::release() {

    }

    void LayerManager::update() {
        for(auto layer : m_layers)
            layer->onUpdate();
    }

    void LayerManager::addLayerToFront(Layer *layer) {
        m_layers.push_back(layer);
        layer->onAttach();
    }

    void LayerManager::removeLayerFromFront() {
        auto layer = m_layers.back();
        m_layers.pop_back();
        layer->onDetach();
        delete layer;
    }

    EventManager::EventCallback LayerManager::getEventCallback() {
        return RAL_BIND_CLASS_FUNCTION(eventCallback);
    }

    void LayerManager::eventCallback(Event* event) {
        for(auto layer : m_layers)
        {
            if(event->isHandled())
                break;
            else
                layer->onEvent(event);
        }
    }

    LayerManager::~LayerManager() {
        if(!m_layers.empty())
        {
            RAL_LOG_WARNING("LayerManager destroyed with layers still attached");
            removeAllLayers();
        }
    }

    void LayerManager::removeAllLayers() {
        for(auto layer : m_layers)
            delete layer;
        m_layers.clear();
    }
} // RAL
