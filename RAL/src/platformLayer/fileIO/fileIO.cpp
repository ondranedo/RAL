#include "fileIO.h"

namespace RAL {

	FileIO::FileIO() {

        openFiles = 0;
	}

	FileIO::~FileIO() {

	}

    bool FileIO::stringCompare(RAL::String a, RAL::String b) {

        /* three levels of nesting is fine ~1nome */
        if(a.size() == b.size()){
            for(u32_t i = 0; i < a.size(); i++){
                if(a.c_str()[i] != b.c_str()[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    i16_t FileIO::findIndex(RAL::String alias){

        RAL_FILE_SCANTHRU{
            RAL_FILE_ISALIAS{
                return i;
            }
        }
        return -1;
    }
}
