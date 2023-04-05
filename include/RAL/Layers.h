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

// Last version of this file: 2023-04-05_20:17

/*
 * Layers are used to separate different parts of the application.
 * For example, you can have a layer for the game logic, a layer for the UI etc.
 *
 */

#ifndef RAL_LAYERS_H
#define RAL_LAYERS_H

#include "MemoryOverload.h"
#include "Event.h"
#include <string>

namespace RAL {
    class Layer {
    public:
        explicit Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;
        virtual void onEvent(Event* event) = 0;
        virtual void onUpdate() = 0;
        virtual void onAttach() = 0;
        virtual void onDetach() = 0;

    private:
        std::string m_name;
    };
} // RAL

#endif //!RAL_LAYERS_H
