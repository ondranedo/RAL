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


#ifndef RAL_PROJECT_FILEMANAGER_H
#define RAL_PROJECT_FILEMANAGER_H
#include <core/memoryManager/Overload.h>
#include <platfomLayer/file/FileFactory.h>

#include <unordered_map>
#include <core/baseClass/BaseComponent.h>

namespace RAL {
    class FileManager final : public BaseComponent {
    public:
        ~FileManager();
        void init() override;
        void release() override;
        void update() override;

        void openTxt(const std::string& alias, const std::string& path, File::Mode mode);
        //void openBin(const std::string& alias, const std::string& path, File::Mode mode);
        void close(const std::string& alias);
        void closeAll();

        const FileTxt * getTxtFile(const std::string& alias) const;
        //FileBin* getBinFile(const std::string& alias);

#ifdef RAL_DEBUG
        void printFiles() const;
#endif // RAL_DEBUG
    private:
        FileFactory m_fileFactory;
        std::unordered_map<std::string, File*> m_files;
    };
} // RAL

#endif //!RAL_PROJECT_FILEMANAGER_H
