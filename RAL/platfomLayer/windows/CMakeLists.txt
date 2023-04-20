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
add_library(ral_platformLayer_windows STATIC
        "Win32GLFW.cpp"
        "Win32GLFW.h"
        "Win32Main.cpp"
        "Win32Main.h"
        "window/Win32Types.cpp"
        "window/Win32Types.h"
        )
endif(WIN32)