#pragma once

#include "pch.h"
#include <cstdio>

// constants for open modes
#define TXT_READ "r"
#define TXT_WRITE "w"
#define TXT_APPEND "a"
#define TXT_READ_WRITE "r+"
#define BIN_READ "rb"
#define BIN_WRITE "wb"
#define BIN_APPEND "ab"
#define BIN_READ_WRITE "rb+"

#define RAL_FILE_ENTRY RAL::Pair<RAL::Pair<RAL::String, RAL::String>, RAL::Pair<RAL::String, FILE*>>

/* TODO: 
*		use String once it has been documented
*		refactor to Memory once platformLayer is complete
*		potentially more overrides for println
*/

namespace RAL {

	class fileIO{
	public:
		fileIO();
		~fileIO();

		void open(RAL::String path, RAL::String alias, RAL::String mode);
		void close(RAL::String alias);

		void println(const i8_t* string);
		void println(i32_t num);
		void println(f32_t num);

		i8_t* readln();

		void printFileUsage();
		
		void maxFile(i16_t count);

	private:

		i16_t openFiles;
        RAL_FILE_ENTRY* files;
	};
}