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
		inline void setPriority(LogPriority new_priority);
		
		//Functions for each priority.
		template<typename... Args> void Trace(const char* message, Args... args);
		template<typename... Args> void Debug(const char* message, Args... args);
		template<typename... Args> void Info(const char* message, Args... args);
		template<typename... Args> void Warning(const char* message, Args... args);
		template<typename... Args> void Error(const char* message, Args... args);
		template<typename... Args> void Critical(const char* message, Args... args);
	};
	
	inline void Logg::setPriority(LogPriority new_priority)
	{
		Logg::priority = new_priority;
	}

	template<typename... Args> void Logg::Trace(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Trace)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Trace]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> void Logg::Debug(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Debug)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Debug]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> void Logg::Info(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Info)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Info]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> void Logg::Warning(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Warning)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Warning]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> void Logg::Error(const char* message, Args... args)
	{
		if (Logg::priority <= LogPriority::Error)
		{
			//std::scoped_lock lock(Logg::log_mutex);
			printf("[Error]\t");
			printf(message, args...);
			printf("\n");
		}
	}

	template<typename... Args> void Logg::Critical(const char* message, Args... args)
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