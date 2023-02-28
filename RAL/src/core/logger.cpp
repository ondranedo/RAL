#include "logger.h"

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
		if (!s_file) printf("Failed to open file: %s", filepath);
		else s_fileDumpEnabled = true;
	}

	void Logger::endDumpFile()
	{
		s_fileDumpEnabled = false;
	}

}

