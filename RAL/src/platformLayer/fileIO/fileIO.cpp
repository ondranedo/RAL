#include "fileIO.h"

#include <utility>

namespace RAL {

	fileIO::fileIO() {

        openFiles = 0;
        files = reinterpret_cast<RAL_FILE_ENTRY*>(malloc(sizeof(RAL_FILE_ENTRY)));
		RAL_LOG_TRACE("File I/O created");
	}

	fileIO::~fileIO() {

        for(i16_t i = 0; i < openFiles; i++){
            fclose(files[i].y.y);
        }
        free(files);
		RAL_LOG_TRACE("File I/O destroyed");
	}

	void fileIO::open(RAL::String path, RAL::String alias, RAL::String mode) {

        for(i16_t i = 0; i < openFiles; i++){
            if(stringCompare(path, files[i].x.x)){
                RAL_LOG_ERROR("This path is already open!");
                return;
            }
            if(stringCompare(alias, files[i].x.y)){
                RAL_LOG_ERROR("This alias is already used!");
                return;
            }
        }

        if(openFiles == _getmaxstdio()){
            RAL_LOG_ERROR("Open file limit reached!");
            return;
        }
        files = reinterpret_cast<RAL_FILE_ENTRY*>(realloc(files, sizeof(RAL_FILE_ENTRY) * (openFiles + 1)));
		files[openFiles].y.y = fopen(path.c_str(), mode.c_str());
        files[openFiles].x.x = path;
        files[openFiles].x.y = alias;
        files[openFiles].y.x = mode;
        openFiles += 1;
	}

    void fileIO::close(RAL::String alias) {

        for(i16_t i = 0; i < openFiles; i++){
            if(stringCompare(alias, files[i].x.y)){
                fclose(files[i].y.y);

                files[i].x.x = files[openFiles - 1].x.x;
                files[i].x.y = files[openFiles - 1].x.y;
                files[i].y.x = files[openFiles - 1].y.x;
                files[i].y.y = files[openFiles - 1].y.y;

                files = reinterpret_cast<RAL_FILE_ENTRY*>(realloc(files, sizeof(RAL_FILE_ENTRY) * (openFiles - 1)));
                openFiles -= 1;
                return;
            }
        }
        RAL_LOG_ERROR("File alias not found!");
    }

    bool fileIO::stringCompare(RAL::String a, RAL::String b) {

        /* three levels of nesting is fine ~1nome */
        if(a.size() == b.size()){
            for(u32_t i = 0; i < a.size(); i++){
                if(a.c_str()[i] != a.c_str()[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    RAL::String fileIO::readln(RAL::String alias){

        char* buf;
        RAL::String buf2 = RAL::String();

        for(i16_t i = 0; i < openFiles; i++){
            if(stringCompare(alias, files[i].x.y)){
                if(files[i].y.x.c_str()[1] == 'b'){

                }
                else{
                    // change to a better solution than this
                    buf = reinterpret_cast<char*>(malloc(1024));
                    fscanf(files[i].y.y, "%s\n", buf);

                    buf2.recreate(buf);
                    free(buf);
                    return buf2;
                }
            }
        }
        RAL_LOG_ERROR("File alias not found!");
    }

	void fileIO::maxFile(i16_t count) {

        if(count < openFiles) {
            RAL_LOG_ERROR("Cant decrease the maximum number of open files now! Need to close some prior to decreasing.");
            return;
        }
        RAL_LOG_TRACE("Maximum number of open files changed to %h", count);
		_setmaxstdio(count);
	}
}
