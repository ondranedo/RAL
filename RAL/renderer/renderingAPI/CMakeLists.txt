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
        platform/openGL/OpenGL.cpp platform/openGL/OpenGL.h platform/openGL/GLVertexBuffer.cpp platform/openGL/GLVertexBuffer.h platform/openGL/GLVertexArray.cpp platform/openGL/GLVertexArray.h platform/openGL/GLIndexBuffer.cpp platform/openGL/GLIndexBuffer.h)

set(vulkan
        # path to vulkan rendering api files
        platform/vulkan/Vulkan.cpp platform/vulkan/Vulkan.h)

set(directX
        # path to directX rendering api files
        platform/directX/DirectX.cpp platform/directX/DirectX.h)

add_library(ral_renderer_renderingAPI STATIC
        RenderingAPI.cpp
        RenderingAPI.h
        ${openGL}
        ${vulkan}
        ${directX}
        RenderingContext.cpp RenderingContext.h VertexBuffer.cpp VertexBuffer.h VertexArray.cpp VertexArray.h IndexBuffer.cpp IndexBuffer.h)