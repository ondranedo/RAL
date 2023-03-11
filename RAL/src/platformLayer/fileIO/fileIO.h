#pragma once

#include "../../containers/string.h"
#include "../../containers/pair.h"
#include "../../core/types.h"
#include "../../core/logger.h"

#define RAL_FILE_ENTRY RAL::Pair<RAL::Pair<RAL::String, RAL::String>, RAL::Pair<RAL::String, FILE*>>

#define RAL_FILE_SCANTHRU for(i16_t i = 0; i < openFiles; i++)
#define RAL_FILE_ISALIAS if(FileIO::stringCompare(alias, files[i].x.y))

namespace RAL {

	class FileIO{
	public:
		FileIO();
		virtual ~FileIO();

        virtual void open(const RAL::String& path, const RAL::String& alias, const RAL::String& mode) = 0;
        virtual void close(const RAL::String& alias) = 0;

        virtual void println(const RAL::String& alias, const RAL::String& string) = 0;
        virtual void println(const RAL::String& alias, i64_t num) = 0;
        virtual void println(const RAL::String& alias, f64_t num) = 0;

        virtual RAL::String readln(const RAL::String& alias) = 0;

        virtual void printFileUsage() = 0;

        virtual void maxFile(i16_t count) = 0;

	protected:

		i16_t openFiles;
        RAL_FILE_ENTRY* files{};

        bool stringCompare(RAL::String a, RAL::String b);
        i16_t findIndex(RAL::String alias);
	};
}