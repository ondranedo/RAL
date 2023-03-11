#pragma once

#include "../../pch.h"

#define RAL_FILE_ENTRY RAL::Pair<RAL::Pair<RAL::String, RAL::String>, RAL::Pair<RAL::String, FILE*>>

#define RAL_FILE_SCANTHRU for(i16_t i = 0; i < openFiles; i++)
#define RAL_FILE_ISALIAS if(FileIO::stringCompare(alias, files[i].x.y))

namespace RAL {

	class FileIO{
	public:
		FileIO();
		virtual ~FileIO();

        virtual void open(RAL::String path, RAL::String alias, RAL::String mode) = 0;
        virtual void close(RAL::String alias) = 0;

        virtual void println(RAL::String alias, RAL::String string) = 0;
        virtual void println(RAL::String alias, i64_t num) = 0;
        virtual void println(RAL::String alias, f64_t num) = 0;

        virtual RAL::String readln(RAL::String alias) = 0;

        virtual void printFileUsage() = 0;

        virtual void maxFile(i16_t count) = 0;

	protected:

		i16_t openFiles;
        RAL_FILE_ENTRY* files{};

        bool stringCompare(RAL::String a, RAL::String b);
        i16_t findIndex(RAL::String alias);
	};
}