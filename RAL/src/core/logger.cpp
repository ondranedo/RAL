#include "logger.h"
#include "asserts.h"
#include "allocator.h"

namespace RAL 
{
	LoggerClass mainLogger;
    std::mutex LoggerClass::s_mutex = std::mutex();
	LoggerClass::LoggerClass() :
        m_console(nullptr),
		m_file(nullptr),
        m_filealias(nullptr),
		m_fileDumpEnabled(false),
		m_priority(LoggerClass::Priority::Info),
		m_prevPriority(LoggerClass::Priority::Info)
	{
	}
	LoggerClass::~LoggerClass()
	{
		if (m_file != nullptr) m_file->close(*m_filealias);
	}

	void LoggerClass::setPriority(Priority new_priority)
	{
		m_prevPriority = m_priority;
		m_priority = new_priority;
	}
	void LoggerClass::setPriorityPrev()
	{
		m_priority = m_prevPriority;
	}
    void LoggerClass::bindToConsole(ConsoleInterpreter* console_ptr)
    {
        m_console = console_ptr;
    }
    void LoggerClass::setFileIO(FileIO *file_ptr)
    {
       m_file = file_ptr;
    }

    void LoggerClass::resetFileIO()
    {
        m_file = nullptr;
    }

    void LoggerClass::detachFromConsole()
    {
        m_console = nullptr;
    }

	void LoggerClass::dumpFile(const RAL::String& filepath)
	{
        if(!m_filealias) m_filealias = mainMemory.alloc<RAL::String>("mainLogger");
        if (!m_file) m_file->close(*m_filealias);
        m_file->open(filepath, *m_filealias, "w");
        //RAL_ASSERT_NULL(m_file, "Failed to open file: %s", filepath);
        if (!m_file) m_fileDumpEnabled = true;

	}

	void LoggerClass::stopDumpFile()
	{
		m_fileDumpEnabled = false;
        m_file->close(*m_filealias);
        mainMemory.release(m_filealias);
        m_filealias = nullptr;
	}

	void LoggerClass::continueDumpFile()
	{
		m_fileDumpEnabled = true;
	}
}

