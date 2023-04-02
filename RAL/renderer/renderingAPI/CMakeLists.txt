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

set(openGL
        # path to openGL rendering api files
        platforms/openGL/OpenGL.cpp platforms/openGL/OpenGL.h)

set(vulkan
        # path to vulkan rendering api files
        platforms/vulkan/Vulkan.cpp platforms/vulkan/Vulkan.h)

set(directX
        # path to directX rendering api files
        platforms/directX/DirectX.cpp platforms/directX/DirectX.h)

add_library(ral_renderer_renderingAPI STATIC
        RenderingAPI.cpp
        RenderingAPI.h
        ${openGL}
        ${vulkan}
        ${directX}
        )