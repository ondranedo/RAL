#pragma once
#include <stdio.h>
#include <mutex>

// TODO:
//	- MUTEX
//	- Platform layer

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
		static Priority priority;
		//static std::mutex log_mutex;
	public:

		//Allows user to change priority.
		static inline void setPriority(Priority new_priority)
		{
			Logger::priority = new_priority;
		}
		
		//Functions for each priority.
		template<typename... Args> static void Trace(const char* message, Args... args);
		template<typename... Args> static void Debug(const char* message, Args... args);
		template<typename... Args> static void Info(const char* message, Args... args);
		template<typename... Args> static void Warning(const char* message, Args... args);
		template<typename... Args> static void Error(const char* message, Args... args);
		template<typename... Args> static void Critical(const char* message, Args... args);
	};

	template<typename... Args> static void Logger::Trace(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Trace)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Trace]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logger::Debug(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Debug)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Debug]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logger::Info(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Info)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Info]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logger::Warning(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Warning)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Warning]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logger::Error(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Error)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Error]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logger::Critical(const char* message, Args... args)
	{
		if (Logger::priority <= Priority::Critical)
		{
			//std::scoped_lock lock(Logger::log_mutex);
			printf("[Crtitical]\t");
			printf(message, args...);
			printf("\n");
		}
	}
};
#ifdef RAL_DEBUG
#define RAL_LOG_TRACE(message,...) RAL::Logger::Trace(message,__VA_ARGS__);
#define RAL_LOG_DEBUG(message,...) RAL::Logger::Debug(message,__VA_ARGS__);
#define RAL_LOG_INFO(message,...) RAL::Logger::Info(message,__VA_ARGS__);
#define RAL_LOG_WARN(message,...) RAL::Logger::Warning(message,__VA_ARGS__);
#define RAL_LOG_ERROR(message,...) RAL::Logger::Error(message,__VA_ARGS__);
#define RAL_LOG_CRIT(message,...) RAL::Logger::Critical(message,__VA_ARGS__);
#define RAL_LOG_PRIORITY_TRACE() RAL::Logger::setPriority(RAL::Logger::Priority::Trace);
#define RAL_LOG_PRIORITY_DEBUG() RAL::Logger::setPriority(RAL::Logger::Priority::Debug);
#define RAL_LOG_PRIORITY_INFO() RAL::Logger::setPriority(RAL::Logger::Priority::Info);
#define RAL_LOG_PRIORITY_WARN() RAL::Logger::setPriority(RAL::Logger::Priority::Warning);
#define RAL_LOG_PRIORITY_ERROR() RAL::Logger::setPriority(RAL::Logger::Priority::Error);
#define RAL_LOG_PRIORITY_CRITICAL() RAL::Logger::setPriority(RAL::Logger::Priority::Critical);
#endif

#ifdef RAL_RELEASE
#define RAL_LOG_TRACE(message,...)
#define RAL_LOG_DEBUG(message,...)
#define RAL_LOG_INFO(message,...) RAL::Logger::Info(message,__VA_ARGS__);
#define RAL_LOG_WARN(message,...) RAL::Logger::Warning(message,__VA_ARGS__);
#define RAL_LOG_ERROR(message,...) RAL::Logger::Error(message,__VA_ARGS__);
#define RAL_LOG_CRIT(message,...) RAL::Logger::Critical(message,__VA_ARGS__);
#define RAL_LOG_SETPRIORITY(priority) RAL::Logger::setPriority(priority);
#define RAL_LOG_PRIORITY_TRACE()
#define RAL_LOG_PRIORITY_DEBUG()
#define RAL_LOG_PRIORITY_INFO() RAL::Logger::setPriority(RAL::Logger::Priority::Info);
#define RAL_LOG_PRIORITY_WARN() RAL::Logger::setPriority(RAL::Logger::Priority::Warning);
#define RAL_LOG_PRIORITY_ERROR() RAL::Logger::setPriority(RAL::Logger::Priority::Error);
#define RAL_LOG_PRIORITY_CRITICAL() RAL::Logger::setPriority(RAL::Logger::Priority::Critical);
#endif

