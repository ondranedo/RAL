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
#ifndef RAL_PROJECT_LAYERMANAGERFACTORY_H
#define RAL_PROJECT_LAYERMANAGERFACTORY_H

#include <core/baseClass/BaseFactory.h>
#include <core/layers/LayerManager.h>

namespace RAL {
    class LayerManagerFactory : public BaseFactory<LayerManager> {
    public:
        LayerManager *create() override;

    public:

    private:
    };
} // RAL

#endif //!RAL_PROJECT_LAYERMANAGERFACTORY_H
