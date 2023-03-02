#pragma once
#include <stdio.h>
#include <mutex>
#include "types.h"
#include "core/defines.h"

// TODO:
//	- MUTEX
//	- Platform layer
//  - Assertions

namespace RAL
{	
	class RAL_API LoggerClass
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

	private:
		template<typename... Args> void log(const char* message_priority_str, LoggerClass::Priority message_priority, const char* message, Args... args) const
		{
			if (m_priority <= message_priority)
			{
				printf(message_priority_str);
				printf(message, args...);
				printf("\n");
			}
			if (m_file != 0 && m_fileDumpEnabled)
			{
				fprintf_s(m_file, message_priority_str);
				fprintf_s(m_file, message, args...);
				fprintf_s(m_file, "\n");
			}
		}

	public:
		LoggerClass();
		~LoggerClass();

		//Allows user to change priority.
		inline void setPriority(Priority new_priority);
		inline void setPriorityPrev();

		//Functions for each priority.
		template<typename... Args> inline void trace(const char* message, Args... args) const;
		template<typename... Args> inline void debug(const char* message, Args... args) const;
		template<typename... Args> inline void info(const char* message, Args... args) const;
		template<typename... Args> inline void warning(const char* message, Args... args) const;
		template<typename... Args> inline void error(const char* message, Args... args) const;
		template<typename... Args> inline void critical(const char* message, Args... args) const;

		void dumpFile(const char* filepath);
		void stopDumpFile();
		void continueDumpFile();
	};

	extern RAL_API LoggerClass mainLogger;

	template<typename... Args> inline void LoggerClass::trace(const char* message, Args... args) const
	{
		log("[Trace]\t", LoggerClass::Priority::Critical, message, args...);
	}

	template<typename... Args> inline void LoggerClass::debug(const char* message, Args... args) const
	{
		log("[Debug]\t", LoggerClass::Priority::Debug, message, args...);
	}

	template<typename... Args> inline void LoggerClass::info(const char* message, Args... args) const
	{
		log("[Info]\t", LoggerClass::Priority::Info, message, args...);
	}

	template<typename... Args> inline void LoggerClass::warning(const char* message, Args... args) const
	{
		log("[Warning]\t", LoggerClass::Priority::Warning, message, args...);
	}

	template<typename... Args> inline void LoggerClass::error(const char* message, Args... args) const
	{
		log("[Error]\t", LoggerClass::Priority::Error, message, args...);
	}

	template<typename... Args> inline void LoggerClass::critical(const char* message, Args... args) const
	{
		log("[Critical]\t", LoggerClass::Priority::Critical, message, args...);
	}
};
#ifdef RAL_DEBUG
#define RAL_LOG_TRACE(...) RAL::mainLogger.trace(__VA_ARGS__);
#define RAL_LOG_DEBUG(...) RAL::mainLogger.debug(__VA_ARGS__);
#define RAL_LOG_PRIORITY_TRACE()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Trace);
#define RAL_LOG_PRIORITY_DEBUG()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Debug);
#endif

#ifdef RAL_RELEASE
#define RAL_LOG_TRACE(...)
#define RAL_LOG_DEBUG(...)
#define RAL_LOG_PRIORITY_TRACE()
#define RAL_LOG_PRIORITY_DEBUG()
#endif

#define RAL_LOG_INFO(...)  RAL::mainLogger.info(__VA_ARGS__);
#define RAL_LOG_WARN(...)  RAL::mainLogger.warning(__VA_ARGS__);
#define RAL_LOG_ERROR(...)  RAL::mainLogger.error(__VA_ARGS__);
#define RAL_LOG_CRIT(...) RAL::mainLogger.critical(__VA_ARGS__);
#define RAL_LOG_PRIORITY_INFO()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Info);
#define RAL_LOG_PRIORITY_WARN()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Warning);
#define RAL_LOG_PRIORITY_ERROR()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Error);
#define RAL_LOG_PRIORITY_CRITICAL()  RAL::mainLogger.setPriority(RAL::LoggerClass::Priority::Critical);
#define RAL_LOG_PRIORITY_PREVIOUS()  RAL::mainLogger.setPriorityPrev();

#define RAL_LOG_CREATEDUMPFILE(path)  RAL::mainLogger.dumpFile(path);
#define RAL_LOG_STOPDUMPFILE() RAL::mainLogger.stopDumpFile();
#define RAL_LOG_CONTINUEDUMPFILE()  RAL::mainLogger.continueDumpFile();