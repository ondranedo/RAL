#include "fileIO.h"

#include <utility>
#include "../../core/logger.h"

namespace RAL {

	fileIO::fileIO() {

        openFiles = 0;
        files = reinterpret_cast<RAL_FILE_ENTRY*>(malloc(sizeof(RAL_FILE_ENTRY)));
		RAL_LOG_TRACE("File I/O created");
	}

	fileIO::~fileIO() {

		RAL_LOG_TRACE("File I/O destroyed");
	}

	void fileIO::open(RAL::String path, RAL::String alias, RAL::String mode) {

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


    }

	void fileIO::maxFile(i16_t count) {

		RAL_LOG_TRACE("Maximum number of open files changed to %hu", count);
		_setmaxstdio(count);
	}
}
