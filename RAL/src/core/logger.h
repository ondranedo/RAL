#pragma once
#include "../platformLayer/fileIO/FileIO.h"
// TODO:
//	- MUTEX
//  - Custom format
#include <mutex>
#include <stdio.h>
#include "../platformLayer/console/consoleInterpreter.h"
#include "../platformLayer/fileIO/fileIO.h"

#define RAL_LOGGER_BUFF_SIZE 200

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
		Priority m_priority;
		Priority m_prevPriority;
		//static std::mutex log_mutex;
		FILE* m_file;
		bool m_fileDumpEnabled;
    ConsoleInterpreter *m_console = nullptr;

		bool                        m_fileDumpEnabled;
        ConsoleInterpreter*    m_console;
        FileIO*                m_file;
        String*                m_filealias;
	private:
		template<typename... Args> void log(const String& message_priority_str, LoggerClass::Priority message_priority,const String& message, ConsoleInterpreter::ColourForeground foreground = ConsoleInterpreter::ColourForeground::WHITE,  ConsoleInterpreter::ColourBackground background = ConsoleInterpreter::ColourBackground::BLACK) const
		{

			if (m_priority <= message_priority && m_console != nullptr)
			{
                m_console->log(message_priority_str,foreground, background);
                m_console->log(message,foreground, background);
                m_console->log("\n");
			}
			if (m_fileDumpEnabled && m_file != nullptr && m_console != nullptr)
			{
                m_file->println(*m_filealias, message_priority_str);
                m_file->println(*m_filealias,message);
                m_file->println(*m_filealias,"\n");
			}
		}

	public:
		LoggerClass();
		~LoggerClass();

		//Allows user to change priority.
		void setPriority(Priority new_priority);
		void setPriorityPrev();

		//Functions for each priority.
		template<typename... Args> inline void trace(const char* msg, Args... args) const;
		template<typename... Args> inline void debug(const char* msg, Args... args) const;
		template<typename... Args> inline void info(const char* msg, Args... args) const;
		template<typename... Args> inline void warning(const char* msg, Args... args) const;
		template<typename... Args> inline void error(const char* msg, Args... args) const;
		template<typename... Args> inline void critical(const char* msg, Args... args) const;

		void dumpFile(const String& filepath);
		void stopDumpFile();
		void continueDumpFile();
    void bindToConsole(ConsoleInterpreter* console_ptr);
    void detachFromConsole();
    void setFileIO(FileIO* file_ptr);
    void resetFileIO();

    template<typename... Args> void argsToMsg(String& message, Args... args);

    static std::mutex s_mutex;
	};

	extern LoggerClass mainLogger;

    template<typename... Args> void LoggerClass::argsToMsg(String& message, Args... args)
    {
        char buff[RAL_LOGGER_BUFF_SIZE];
        snprintf(buff,RAL_LOGGER_BUFF_SIZE,message.c_str(), args...);
        message.recreate(buff);
    }

	template<typename... Args> inline void LoggerClass::trace(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Trace]\t", LoggerClass::Priority::Critical, message, ConsoleInterpreter::ColourForeground::GRAY);
    }
  
	template<typename... Args> inline void LoggerClass::debug(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        RAL::String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Debug]\t", LoggerClass::Priority::Debug, message, ConsoleInterpreter::ColourForeground::BROWN);
    }

	template<typename... Args> inline void LoggerClass::info(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Info]\t", LoggerClass::Priority::Info, message, ConsoleInterpreter::ColourForeground::GREEN);
    }

	template<typename... Args> inline void LoggerClass::warning(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Warning]\t", LoggerClass::Priority::Warning, message, ConsoleInterpreter::ColourForeground::YELLOW);
    }
  
	template<typename... Args> inline void LoggerClass::error(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Error]\t", LoggerClass::Priority::Error, message, ConsoleInterpreter::ColourForeground::RED);
    }
  
	template<typename... Args> inline void LoggerClass::critical(const char* msg, Args... args) const
	{
        std::lock_guard<std::mutex> guard(s_mutex);
        String message;
        message.recreate(msg);
        mainLogger.argsToMsg(message, args...);
		log("[Critical]\t", LoggerClass::Priority::Critical,  message, ConsoleInterpreter::ColourForeground::WHITE, ConsoleInterpreter::ColourBackground::RED);
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




