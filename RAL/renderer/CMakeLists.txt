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

add_library(ral_renderer STATIC
        Renderer.cpp
        Renderer.h)

add_subdirectory(renderer2d)
target_link_libraries(ral_renderer PUBLIC ral_renderer_renderer2d)

add_subdirectory(renderingAPI)
target_link_libraries(ral_renderer PUBLIC ral_renderer_renderingAPI)

add_subdirectory(scene)
target_link_libraries(ral_renderer PUBLIC ral_renderer_scene)

add_subdirectory(mesh)
target_link_libraries(ral_renderer PUBLIC ral_renderer_mesh)

add_subdirectory(entity)
target_link_libraries(ral_renderer PUBLIC ral_renderer_entity)

add_subdirectory(material)
target_link_libraries(ral_renderer PUBLIC ral_renderer_material)

add_subdirectory(texture)
target_link_libraries(ral_renderer PUBLIC ral_renderer_texture)
