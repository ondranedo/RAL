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

#ifndef RAL_BASEGAME_H
#define RAL_BASEGAME_H


namespace RAL {
    class BaseGame {
    public:
        // TODO: Add more layer methods
        //virtual void addLayer(Layer* layer) = 0;

        virtual void onUpdate() = 0;
        virtual void onStartup() = 0;
        virtual void onShutdown() = 0;

        BaseGame();
        virtual ~BaseGame();
    };

    // TODO: Custom class, some factory
    extern BaseGame* createBaseGame();
} // RAL

#endif //!RAL_BASEGAME_H
