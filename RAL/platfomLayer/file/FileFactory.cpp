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


#include "FileFactory.h"

#ifdef RAL_WINDOWS
#include <platfomLayer/windows/File/Win32FileTxt.h>
#endif
#include <core/utility/Asserts.h>

namespace RAL {

	File* FileFactory::create()
	{
        return createTxt();
	}

    FileTxt *FileFactory::createTxt() {
#ifdef RAL_WINDOWS
        return dynamic_cast<FileTxt*>(createPass(dynamic_cast<File*>(new Win32::Win32FileTxt)));
#endif
        RAL_ASSERTR(false, nullptr, "Unknown platform when creating txt file");
    }

} // RAL