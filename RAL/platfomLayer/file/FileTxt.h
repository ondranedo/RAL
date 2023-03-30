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


#ifndef RAL_PROJECT_FILETXT_H
#define RAL_PROJECT_FILETXT_H

#include <platfomLayer/file/File.h>

#define RAL_FILE_TXT_MAX_LINE_WIDTH 1024

namespace RAL {
    class FileTxt : public virtual File {
    public:
        virtual ~FileTxt() = default;
        virtual std::optional<std::vector<std::string>> read() const = 0;
        virtual std::optional<std::string> readLine() const = 0;

        virtual void write(const std::vector<std::string> &data) const = 0;
        virtual void write(const std::string &data) const = 0;
        template<typename ... Args>
        void write(Args... args) const;

        virtual void reset() const = 0;
    };

	template<typename ... Args>
    void FileTxt::write(Args... args) const
    {
        char buff[RAL_FILE_TXT_MAX_LINE_WIDTH] = { 0 };
        sprintf_s(buff, RAL_FILE_TXT_MAX_LINE_WIDTH, args...);
        write(std::string(buff));
    }
} // RAL

#endif //!RAL_PROJECT_FILETXT_H
