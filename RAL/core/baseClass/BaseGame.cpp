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


#include "BaseGame.h"

#include <core/utility/Asserts.h>

namespace RAL {
    BaseGame::~BaseGame()
    {
        RAL_LOG_DEBUG("Base game destroyed!");
    }
    BaseGame::BaseGame(): m_layerManager(nullptr) {
        RAL_LOG_DEBUG("Base game created!");
    }


    void BaseGame::addLayer(Layer *layer) {
        RAL_ASSERTRV(m_layerManager != nullptr, "LayerManager is not set when creating game!");
        m_layerManager->addLayerToFront(layer);
        RAL_LOG_DEBUG("Added layer to the front in base game!");
    }

    void BaseGame::setLayerManager(const LayerManager *layerManager) {
        RAL_ASSERTRV(m_layerManager == nullptr, "LayerManager is already set!");
        m_layerManager = const_cast<LayerManager*>(layerManager);
    }
} // RAL