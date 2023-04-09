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
#ifndef RAL_PROJECT_LAYERMANAGER_H
#define RAL_PROJECT_LAYERMANAGER_H

#include <vector>
#include <core/layers/Layer.h>
#include <core/baseClass/BaseComponent.h>
#include <core/events/EventManager.h>

namespace RAL {
    class LayerManager final : public BaseComponent {
    public:
        ~LayerManager() override;

        void init() override;
        void release() override;
        void update() override;

        void addLayerToFront(Layer* layer);
        void removeLayerFromFront();
        void removeAllLayers();

        EventManager::EventCallback getEventCallback();

    private:
        void eventCallback(Event* event);
        std::vector<Layer*> m_layers;
    };
} // RAL

#endif //!RAL_PROJECT_LAYERMANAGER_H
