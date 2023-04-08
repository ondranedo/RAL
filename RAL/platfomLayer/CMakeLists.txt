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

add_library(ral_platformLayer STATIC
        PlatformLayer.cpp
        PlatformLayer.h
        )

add_subdirectory(file)
target_link_libraries(ral_platformLayer PRIVATE ral_platformLayer_file)

add_subdirectory(window)
target_link_libraries(ral_platformLayer PRIVATE ral_platformLayer_window)

if(WIN32)
add_subdirectory(windows)
target_link_libraries(ral_platformLayer PUBLIC ral_platformLayer_windows)
endif()

add_subdirectory(memory)
target_link_libraries(ral_platformLayer PRIVATE ral_platformLayer_memory)

add_subdirectory(consoleInterpreter)
target_link_libraries(ral_platformLayer PRIVATE ral_platformLayer_consoleInterpreter)
