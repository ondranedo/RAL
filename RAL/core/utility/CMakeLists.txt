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
# Core utils, used to provide some basic utilities,
# such as logging, assertions, data types, data types
# conversion etc.
add_library(ral_core_utility STATIC
        Asserts.h Logger.cpp Logger.h LogMsg.h LogMsg.cpp Types.cpp Types.h)