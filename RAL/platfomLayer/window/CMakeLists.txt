#######################################################
# Copyright (C) 2023                                  #
# Ondřej Nedojedlý (https://www.github.com/ondranedo),#
# Matyáš Noska (https://www.github.com/sutiama),      #
# Vojtěch Šokala (https://github.com/Karnatour),      #
# Adam Wiszczor (https://github.com/1nome).           #
#                                                     #
# This file is part of `RAL_PROJECT` project          #
# which is released under `GNU General Public         #
# License v3.0` license.                              #
# See file `LICENSE` for full license details.        #
#######################################################

if(WIN32)
    set(platform
            ../windows/window/Win32Window.cpp
            ../windows/window/Win32Window.h
            )
endif()

add_library(ral_platformLayer_window STATIC
        Window.cpp
        Window.h
        WindowFactory.cpp
        WindowFactory.h
        WindowSpec.cpp
        WindowSpec.h
        ${platform}
        )

