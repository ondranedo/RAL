#pragma once
#include <stdio.h>
#include <mutex>
#include "types.h"

// TODO:
//	- MUTEX
//	- Platform layer
//  - Assertions

namespace RAL
{
	
	class Logger
	{
	public:
		//types of priorities
		enum class Priority
		{
			Trace, Debug, Info, Warning, Error, Critical
		};
	private:
		//Priority variable is set to 'Info' by default
		static Priority s_priority;
		//static std::mutex log_mutex;
		static FILE* s_file;
		static const char* s_filepath;
		static bool s_fileDumpEnabled;
	public:

		//Allows user to change priority.
		static inline void setPriority(Priority new_priority)
		{
			Logger::s_priority = new_priority;
		}
		template<typename... Args> static void log(const char* message_priority_str, Logger::Priority message_priority, const char* message, Args... args)
		{
			if (Logger::s_priority <= message_priority)
			{
				printf(message_priority_str);
				printf(message, args...);
				printf("\n");
			}
			if (Logger::s_file != 0 && Logger::s_fileDumpEnabled)
			{
				fprintf_s(Logger::s_file, message_priority_str);
				fprintf_s(Logger::s_file, message, args...);
				fprintf_s(Logger::s_file, "\n");
			}
		}
		//Functions for each priority.
		template<typename... Args> inline static void Trace(const char* message, Args... args);
		template<typename... Args> inline static void Debug(const char* message, Args... args);
		template<typename... Args> inline static void Info(const char* message, Args... args);
		template<typename... Args> inline static void Warning(const char* message, Args... args);
		template<typename... Args> inline static void Error(const char* message, Args... args);
		template<typename... Args> inline static void Critical(const char* message, Args... args);

		static void dumpFile(const char* filepath);
		static void stopDumpFile();
		static void continueDumpFile();
	};

	template<typename... Args> inline static void  Logger::Trace(const char* message, Args... args)
	{
		Logger::log("[Trace]\t", Logger::Priority::Critical, message, args...);
	}

	template<typename... Args> inline static void  Logger::Debug(const char* message, Args... args)
	{
		Logger::log("[Debug]\t", Logger::Priority::Debug, message, args...);
	}

	template<typename... Args> inline static void Logger::Info(const char* message, Args... args)
	{
		Logger::log("[Info]\t", Logger::Priority::Info, message, args...);
	}

	template<typename... Args> static void Logger::Warning(const char* message, Args... args)
	{
		Logger::log("[Warning]\t", Logger::Priority::Warning, message, args...);
	}

	template<typename... Args> inline static void  Logger::Error(const char* message, Args... args)
	{
		Logger::log("[Error]\t", Logger::Priority::Error, message, args...);
	}

	template<typename... Args> inline static void  Logger::Critical(const char* message, Args... args)
	{
		log("[Critical]\t", Logger::Priority::Critical, message, args...);
	}
};
#ifdef RAL_DEBUG
#define RAL_LOG_TRACE(message,...) RAL::Logger::Trace(message,__VA_ARGS__);
#define RAL_LOG_DEBUG(message,...) RAL::Logger::Debug(message,__VA_ARGS__);
#define RAL_LOG_PRIORITY_TRACE() RAL::Logger::setPriority(RAL::Logger::Priority::Trace);
#define RAL_LOG_PRIORITY_DEBUG() RAL::Logger::setPriority(RAL::Logger::Priority::Debug);
#endif

#ifdef RAL_RELEASE
#define RAL_LOG_TRACE(message,...)
#define RAL_LOG_DEBUG(message,...)
#define RAL_LOG_PRIORITY_TRACE()
#define RAL_LOG_PRIORITY_DEBUG()
#endif

#define RAL_LOG_INFO(message,...) RAL::Logger::Info(message,__VA_ARGS__);
#define RAL_LOG_WARN(message,...) RAL::Logger::Warning(message,__VA_ARGS__);
#define RAL_LOG_ERROR(message,...) RAL::Logger::Error(message,__VA_ARGS__);
#define RAL_LOG_CRIT(message,...) RAL::Logger::Critical(message,__VA_ARGS__);
#define RAL_LOG_PRIORITY_INFO() RAL::Logger::setPriority(RAL::Logger::Priority::Info);
#define RAL_LOG_PRIORITY_WARN() RAL::Logger::setPriority(RAL::Logger::Priority::Warning);
#define RAL_LOG_PRIORITY_ERROR() RAL::Logger::setPriority(RAL::Logger::Priority::Error);
#define RAL_LOG_PRIORITY_CRITICAL() RAL::Logger::setPriority(RAL::Logger::Priority::Critical);

#define RAL_LOG_STOPDUMPFILE() RAL::Logger::stopDumpFile();
#define RAL_LOG_CONTINUEDUMPFILE() RAL::Logger::continueDumpFile();

