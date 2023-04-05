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
 * Base game class, which is used to create games.
 * It is used to create games, which are then constructed and
 * used in the RAL engine. You have to implement the createGame
 * function, which is used to create the game.
 */

#ifndef RAL_PROJECT_GAMES_H
#define RAL_PROJECT_GAMES_H

#include "MemoryOverload.h"
#include "Layers.h"

namespace RAL {
    class LayerManager;
    enum class GameType {
        BASE_GAME
    };
    class BaseGame {
    public:
        void addLayer(Layer* layer);

        virtual void onUpdate() = 0;
        virtual void onStartup() = 0;
        virtual void onShutdown() = 0;

        BaseGame();
        virtual ~BaseGame();

    private:
        LayerManager* m_layerManager;
    };

    extern BaseGame* createGame();
} // RAL

#endif //!RAL_PROJECT_GAMES_H
