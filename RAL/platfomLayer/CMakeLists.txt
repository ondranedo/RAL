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
add_subdirectory(windows)
target_link_libraries(${RAL_ENGINE_LIB} PUBLIC ral_platformLayer_windows)
endif()

add_subdirectory(memory)
target_link_libraries(${RAL_ENGINE_LIB} PUBLIC ral_platformLayer_memory)

add_subdirectory(window)
target_link_libraries(${RAL_ENGINE_LIB} PUBLIC ral_platformLayer_window)

add_subdirectory(file)
target_link_libraries(${RAL_ENGINE_LIB} PUBLIC ral_platformLayer_file)