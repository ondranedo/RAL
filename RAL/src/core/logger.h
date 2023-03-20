#pragma once

// TODO:
//	- MUTEX
//  - Custom format

#include <stdio.h>
#include "../platformLayer/console/consoleInterpreter.h"
#include "../platformLayer/fileIO/fileIO.h"
#include <mutex>

namespace RAL
{	
	class LoggerClass
	{
	public:
		//types of priorities
		enum class Priority
		{
			Trace, Debug, Info, Warning, Error, Critical
		};
	private:
		//Priority variable is set to 'Info' by default
		Priority                    m_priority;
		Priority                    m_prevPriority;

        //TODO: should use platform layer
        static std::mutex            m_mutex;
        //

		bool                        m_fileDumpEnabled;
        RAL::ConsoleInterpreter*    m_console = nullptr;
        RAL::FileIO*                m_file = nullptr;
        RAL::String                 m_filename = "log";
	private:
		template<typename... Args> void log(const RAL::String& message_priority_str, LoggerClass::Priority message_priority, RAL::String message,ConsoleInterpreter::ColourForeground foreground = ConsoleInterpreter::ColourForeground::WHITE,  ConsoleInterpreter::ColourBackground background = ConsoleInterpreter::ColourBackground::BLACK) const
		{
			if (m_priority <= message_priority && !m_console)
			{
				m_console->log(message_priority_str, background, foreground);
				m_console->log(message,background, foreground);
				m_console->log("\n");
			}
			if (m_file != nullptr && m_fileDumpEnabled && !m_console)
			{
                m_file->println(m_filename, message_priority_str);
                m_file->println(m_filename,message);
                m_file->println(m_filename,"\n");
			}
		}

	public:
		LoggerClass();
		~LoggerClass();

		//Allows user to change priority.
		void setPriority(Priority new_priority);
		void setPriorityPrev();

		//Functions for each priority.
		template<typename... Args> inline void trace(const RAL::String& message, Args... args) const;
		template<typename... Args> inline void debug(const RAL::String& message, Args... args) const;
		template<typename... Args> inline void info(const RAL::String& message, Args... args) const;
		template<typename... Args> inline void warning(const RAL::String& message, Args... args) const;
		template<typename... Args> inline void error(const RAL::String& message, Args... args) const;
		template<typename... Args> inline void critical(const RAL::String& message, Args... args) const;

		void dumpFile(const RAL::String& filepath);
		void stopDumpFile();
		void continueDumpFile();
        void bindToConsole(ConsoleInterpreter* console_ptr);
        void setFileIO(FileIO* file_ptr);
	};

	extern LoggerClass mainLogger;

	template<typename... Args> inline void LoggerClass::trace(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Trace]\t", LoggerClass::Priority::Critical, message, ConsoleInterpreter::ColourForeground::GRAY);
    }
  
	template<typename... Args> inline void LoggerClass::debug(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Debug]\t", LoggerClass::Priority::Debug, message, ConsoleInterpreter::ColourForeground::BROWN);
    }

	template<typename... Args> inline void LoggerClass::info(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Info]\t", LoggerClass::Priority::Info, message, ConsoleInterpreter::ColourForeground::GREEN);
    }

	template<typename... Args> inline void LoggerClass::warning(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Warning]\t", LoggerClass::Priority::Warning, message, ConsoleInterpreter::ColourForeground::YELLOW);
    }
  
	template<typename... Args> inline void LoggerClass::error(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Error]\t", LoggerClass::Priority::Error, message, ConsoleInterpreter::ColourForeground::RED);
    }
  
	template<typename... Args> inline void LoggerClass::critical(const RAL::String& message, Args... args) const
	{
        std::lock_guard<std::mutex> guard(m_mutex);
		log("[Critical]\t", LoggerClass::Priority::Critical, message, ConsoleInterpreter::ColourForeground::WHITE, ConsoleInterpreter::ColourBackground::RED);
    }
};

#ifdef RAL_DEBUG
#define RAL_LOG_TRACE(...)            RAL::mainLogger.trace(__VA_ARGS__)
#define RAL_LOG_DEBUG(...)            RAL::mainLogger.debug(__VA_ARGS__)
#define RAL_LOG_INFO(...)			  RAL::mainLogger.info(__VA_ARGS__)
#define RAL_LOG_WARN(...)			  RAL::mainLogger.warning(__VA_ARGS__)
#define RAL_LOG_ERROR(...)			  RAL::mainLogger.error(__VA_ARGS__)
#define RAL_LOG_CRIT(...)			  RAL::mainLogger.critical(__VA_ARGS__)

#define RAL_LOG_PRIORITY_TRACE()      RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Trace)
#define RAL_LOG_PRIORITY_DEBUG()      RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Debug)
#define RAL_LOG_PRIORITY_INFO()       RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Info)
#define RAL_LOG_PRIORITY_WARN()       RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Warning)
#define RAL_LOG_PRIORITY_ERROR()      RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Error)
#define RAL_LOG_PRIORITY_CRITICAL()   RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Critical)
#define RAL_LOG_PRIORITY_PREVIOUS()   RAL::mainLogger.setPriorityPrev()

#define RAL_LOG_CREATEDUMPFILE(path)  RAL::mainLogger.dumpFile(path)
#define RAL_LOG_STOPDUMPFILE()        RAL::mainLogger.stopDumpFile()
#define RAL_LOG_CONTINUEDUMPFILE()    RAL::mainLogger.continueDumpFile()
#else
#define RAL_LOG_TRACE(...)
#define RAL_LOG_DEBUG(...)
#define RAL_LOG_INFO(...)			  RAL::mainLogger.info(__VA_ARGS__)
#define RAL_LOG_WARN(...)			  RAL::mainLogger.warning(__VA_ARGS__)
#define RAL_LOG_ERROR(...)			  RAL::mainLogger.error(__VA_ARGS__)
#define RAL_LOG_CRIT(...)			  RAL::mainLogger.critical(__VA_ARGS__)

#define RAL_LOG_PRIORITY_TRACE()
#define RAL_LOG_PRIORITY_DEBUG()
#define RAL_LOG_PRIORITY_INFO()       RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Info)
#define RAL_LOG_PRIORITY_WARN()       RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Warning)
#define RAL_LOG_PRIORITY_ERROR()      RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Error)
#define RAL_LOG_PRIORITY_CRITICAL()   RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Critical)
#define RAL_LOG_PRIORITY_PREVIOUS()   RAL::mainLogger.setPriorityPrev()

#define RAL_LOG_CREATEDUMPFILE(path)  RAL::mainLogger.dumpFile(path)
#define RAL_LOG_STOPDUMPFILE()        RAL::mainLogger.stopDumpFile()
#define RAL_LOG_CONTINUEDUMPFILE()    RAL::mainLogger.continueDumpFile()
#endif




