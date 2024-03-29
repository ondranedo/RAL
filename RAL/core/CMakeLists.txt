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

#######################################################
# CMake for  RAL ENGINE source                        #
#######################################################
# links subcomponents together

add_library(ral_core STATIC
        Main.cpp
        Application.cpp
        Application.h
        Core.h
        )

#######################################################
# Subcomponents                                       #
#######################################################
# Core utils, used to provide some basic utilities,
# such as logging, assertions, data types, data types
# conversion etc.
add_subdirectory(memoryManager)
target_link_libraries(ral_core PRIVATE ral_core_memoryManager)

# factory-component manager, used to create and manage
# components and their factories
add_subdirectory(utility)
target_link_libraries(ral_core PRIVATE ral_core_utility)

# baseClasses (interfaces) for many parts of the engine
add_subdirectory(baseClass)
target_link_libraries(ral_core PRIVATE ral_core_baseClass)

# file manager, used to load and save files
add_subdirectory(fileManager)
target_link_libraries(ral_core PRIVATE ral_core_fileManager)

# layers
add_subdirectory(layers)
target_link_libraries(ral_core PRIVATE ral_core_layers)

# events
add_subdirectory(events)
target_link_libraries(ral_core PRIVATE ral_core_events)

# FCM - factory-component manager, used to create and manage
# components and their factories
add_subdirectory(FCM)
target_link_libraries(ral_core PRIVATE ral_core_FCM)