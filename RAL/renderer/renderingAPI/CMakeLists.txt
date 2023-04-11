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
        platform/openGL/GLRenderingAPI.cpp
        platform/openGL/GLRenderingAPI.h
        platform/openGL/GLVertexBuffer.cpp
        platform/openGL/GLVertexBuffer.h
        platform/openGL/GLVertexArray.cpp
        platform/openGL/GLVertexArray.h
        platform/openGL/GLIndexBuffer.cpp
        platform/openGL/GLIndexBuffer.h platform/openGL/GLIndexable.cpp platform/openGL/GLIndexable.h)

add_library(ral_renderer_renderingAPI STATIC
        RenderingAPI.cpp
        RenderingAPI.h
        ${openGL}
        buffers/VertexBuffer.cpp
        buffers/VertexBuffer.h
        buffers/IndexBuffer.cpp
        buffers/IndexBuffer.h
        buffers/Buffer.cpp
        buffers/Buffer.h buffers/VertexBufferLayout.cpp buffers/VertexBufferLayout.h)