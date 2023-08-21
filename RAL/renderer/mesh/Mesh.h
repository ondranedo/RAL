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

#ifndef RAL_PROJECT_MESH_H
#define RAL_PROJECT_MESH_H

#include <string>

namespace RAL {
    class Mesh {

        //todo: potentially make a factory for use in model creator
    public:
        Mesh();
        ~Mesh();

        virtual void openRalms();
        void openRalms(const std::string& path);
        virtual void saveRalms();
        void saveRalms(const std::string& path);

        std::string getPath();
        void setPath(std::string path);

    private:
        std::string m_path;
    };
} // RAL

#endif //RAL_PROJECT_MESH_H
