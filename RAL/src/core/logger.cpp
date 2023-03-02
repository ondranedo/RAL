#include "logger.h"
#include "asserts.h"

namespace RAL 
{
	RAL_API LoggerClass mainLogger;

	LoggerClass::LoggerClass():
		m_file(nullptr),
		m_fileDumpEnabled(false),
		m_priority(LoggerClass::Priority::Info)
	{
		RAL_LOG_TRACE("Logger initialized");
	}
	LoggerClass::~LoggerClass()
	{
		RAL_LOG_TRACE("Logger released");
	}

	void LoggerClass::dumpFile(const char* filepath)
	{
		if (m_file != nullptr) fclose(m_file);
		fopen_s(&m_file, filepath, "w");
		RAL_ASSERT_NULL(m_file, "Failed to open file: %s", filepath);
		if (!m_file) m_fileDumpEnabled = true;
	}

	void LoggerClass::stopDumpFile()
	{
		m_fileDumpEnabled = false;
	}

	void LoggerClass::continueDumpFile()
	{
		m_fileDumpEnabled = true;
	}
}

