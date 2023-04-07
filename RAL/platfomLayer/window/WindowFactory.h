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

#ifndef RAL_PROJECT_WINDOWFACTORY_H
#define RAL_PROJECT_WINDOWFACTORY_H

#include <core/baseClass/BaseFactory.h>
#include <platfomLayer/window/Window.h>
#include <core/utility/Asserts.h>

#ifdef RAL_WINDOWS
#include <platfomLayer/windows/window/Win32Window.h>
#endif

namespace RAL{
    class WindowFactory final : public BaseFactory {
    public:
        Window *create() override;

        template<class... Args>
        Window *create(Args... args);

        [[nodiscard]] std::string productName() const override;
    };


    template<class... Args>
    Window *WindowFactory::create(Args... args) {
#ifdef RAL_WINDOWS
        return RAL_BASEFACTORY_CREATE_ADR(Win32::Win32Window, new Win32::Win32Window(args...));
#endif
        RAL_ASSERTR(false, nullptr, "Unknown platform when creating window");
    }
};


#endif //!RAL_PROJECT_WINDOWFACTORY_H
