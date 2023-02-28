#pragma once
#include <stdio.h>
#include <mutex>

// TODO:
//	- MUTEX
//	- Platform layer

namespace Logger
{
	enum LogPriority
	{
		Trace, Debug, Info, Warning, Error, Critical
	};

	class Logg
	{
	private:
		//Priority variable is set to 'Info' by default
		static LogPriority priority;
		//static std::mutex log_mutex;
	public:

		//Allows user to change priority.
		static inline void setPriority(LogPriority new_priority)
		{
			Logg::priority = new_priority;
		}
		
		//Functions for each priority.
		template<typename... Args> static void Trace(const char* message, Args... args);
		template<typename... Args> static void Debug(const char* message, Args... args);
		template<typename... Args> static void Info(const char* message, Args... args);
		template<typename... Args> static void Warning(const char* message, Args... args);
		template<typename... Args> static void Error(const char* message, Args... args);
		template<typename... Args> static void Critical(const char* message, Args... args);
	};

	template<typename... Args> static void Logg::Trace(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Trace)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Trace]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logg::Debug(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Debug)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Debug]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logg::Info(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Info)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Info]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logg::Warning(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Warning)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Warning]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logg::Error(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Error)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Error]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> static void Logg::Critical(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Critical)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Crtitical]\t");
			printf(message, args...);
			printf("\n");
		}
	}
};
#ifdef RAL_DEBUG
#define RAL_LOG_TRACE(message,...) Logger::Logg::Trace(message,__VA_ARGS__);
#define RAL_LOG_DEBUG(message,...) Logger::Logg::Debug(message,__VA_ARGS__);
#define RAL_LOG_INFO(message,...) Logger::Logg::Info(message,__VA_ARGS__);
#define RAL_LOG_WARN(message,...) Logger::Logg::Warning(message,__VA_ARGS__);
#define RAL_LOG_ERROR(message,...) Logger::Logg::Error(message,__VA_ARGS__);
#define RAL_LOG_CRIT(message,...) Logger::Logg::Critical(message,__VA_ARGS__);
#endif

#ifdef RAL_RELEASE
#define RAL_LOG_TRACE(message,...)
#define RAL_LOG_DEBUG(message,...)
#define RAL_LOG_INFO(message,...) Logger::Logg::Info(message,__VA_ARGS__);
#define RAL_LOG_WARN(message,...) Logger::Logg::Warning(message,__VA_ARGS__);
#define RAL_LOG_ERROR(message,...) Logger::Logg::Error(message,__VA_ARGS__);
#define RAL_LOG_CRIT(message,...) Logger::Logg::Critical(message,__VA_ARGS__);
#endif

