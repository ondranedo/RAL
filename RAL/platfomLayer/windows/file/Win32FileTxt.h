/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch local (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////


#ifndef RAL_PROJECT_WIN32FILETXT_H
#define RAL_PROJECT_WIN32FILETXT_H
#ifdef RAL_WINDOWS

#include <core/memoryManager/Overload.h>
#include <platfomLayer/file/FileTxt.h>
#include <platfomLayer/windows/file/Win32File.h>

#include <vector>

namespace RAL::Win32 {
    class Win32FileTxt : public virtual FileTxt, public virtual Win32File {
    public:
        Win32FileTxt();
        ~Win32FileTxt() override;

        std::optional<std::vector<std::string>> read() const override;
        std::optional<std::string> readLine() const override;

        void write(const std::vector<std::string> &data) const override;
        void write(const std::string &data) const override;

        void reset() const override;
    private:
		const char* getModeInFormat(Mode mode) override;
    };
} // RAL

#endif //!RAL_WINDOWS
#endif //!RAL_PROJECT_WIN32FILETXT_H
