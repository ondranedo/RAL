/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#ifdef RAL_WINDOWS
#include <core/Core.h>

#ifdef RAL_WINDOWS_USE_WINMAIN
#include "WinMain.h"

#include <core/memoryManager/Overload.h>
#include <core/Main.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


int WinMain(HINSTANCE , HINSTANCE, LPSTR, int)
{
    DWORD processID;
    GetWindowThreadProcessId(GetConsoleWindow(), &processID);
    AllocConsole();
	
    //RAL::main({});

    while (1);
    return 1;
}

#endif
#endif //!RAL_WINDOWS