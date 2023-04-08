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

cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)
project(Glad)

add_library(glad include/glad/glad.h src/glad.c)
target_include_directories(glad PUBLIC include/)