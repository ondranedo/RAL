#include "fileIO.h"
#include "../../core/logger.h"

namespace RAL {

	fileIO::fileIO() {

		RAL_LOG_TRACE("File I/O created");
	}

	fileIO::~fileIO() {

		RAL_LOG_TRACE("File I/O destroyed");
	}

	void fileIO::open(const i8_t* path, const i8_t* alias, const i8_t* mode) {

		fopen(path, mode);
	}


	void fileIO::maxFile(u16_t count) {

		RAL_LOG_TRACE("Maximum number of open files changed to %hu", count);
		_setmaxstdio = count;
	}
}
