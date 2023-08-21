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
            ../windows/file/Win32FileTxt.cpp
            ../windows/file/Win32FileTxt.h
            ../windows/file/Win32File.cpp
            ../windows/file/Win32File.h
            ../windows/file/Win32FileBin.cpp
            ../windows/file/Win32FileBin.h)
endif()

add_library(ral_platformLayer_file STATIC
    File.cpp
    File.h
    FileFactory.cpp
    FileFactory.h
    ${platform} FileTxt.cpp FileTxt.h FileBin.cpp FileBin.h)