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

#include <core/memoryManager/Overload.h>

#include "FileManager.h"

namespace RAL {
    void FileManager::init() {

    }

    void FileManager::release() {

    }

    void FileManager::update() {

    }

    void FileManager::openTxt(const std::string &alias, const std::string &path, File::Mode mode) {
        if(m_files.find(alias) != m_files.end()) {
            RAL_LOG_ERROR("File with alias: %s already exists!", alias.c_str());
            return;
        }
        auto file = m_fileFactory.create();
        file->open(path, mode);
        m_files[alias] = file;
    }

    void FileManager::close(const std::string &alias) {
        if(m_files.find(alias) == m_files.end()) {
            RAL_LOG_ERROR("File with alias: %s does not exist!", alias.c_str());
            return;
        }
        m_files[alias]->close();
        m_fileFactory.destroy(m_files[alias]);
        m_files.erase(alias);
    }

    void FileManager::closeAll() {
        for(auto&[alias, file] : m_files)
        {
            file->close();
            m_fileFactory.destroy(file);
        }
        m_files.clear();
    }

    const FileTxt * FileManager::getTxtFile(const std::string &alias) const {
        if(m_files.find(alias) == m_files.end()) {
            RAL_LOG_ERROR("File with alias: %s does not exist!", alias.c_str());
            return nullptr;
        }

        return dynamic_cast<FileTxt*>(m_files.at(alias));
    }

#ifdef RAL_DEBUG
    void FileManager::printFiles() const {
        for(auto&[alias, file] : m_files)
        {
            RAL_LOG_DEBUG("File: %s, alias: %s", file->getPath().c_str(), alias.c_str());
        }
    }

    FileManager::~FileManager() {
        if(m_files.size() > 0)
        {
            RAL_LOG_WARNING("FileManager is being destroyed with %d files still open!", m_files.size());
            closeAll();
        }
    }

#endif
} // RAL