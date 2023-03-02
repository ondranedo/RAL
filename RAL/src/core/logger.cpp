#include "logger.h"
#include "asserts.h"

namespace RAL 
{
	Logger::Priority Logger::s_priority = Logger::Priority::Info;
	FILE* Logger::s_file = nullptr;
	bool Logger::s_fileDumpEnabled = false;
	//std::mutex Logg::log_mutex;

	void Logger::dumpFile(const char* filepath)
	{
		if (Logger::s_file != nullptr) fclose(Logger::s_file);
		fopen_s(&s_file, filepath, "w");
		RAL_ASSERT_NULL(s_file, "Failed to open file: %s", filepath);
		if (!s_file) s_fileDumpEnabled = true;
	}

	void Logger::stopDumpFile()
	{
		s_fileDumpEnabled = false;
	}

	void Logger::continueDumpFile()
	{
		s_fileDumpEnabled = true;
	}

}

