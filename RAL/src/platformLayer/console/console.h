#pragma once
#include "core/logger.h"
#include "core/asserts.h"
#define RAL_WINDOWS

namespace RAL
{
	class Console
	{
	public:
		virtual void setTitle(const char* title) = 0;
		virtual ~Console();
	};
};

#ifdef RAL_WINDOWS
#include "Wconsole.h"
#endif // _DEBUG
#ifdef RAL_LINUX
#include "Lconsole.h"
#endif // _DEBUG
#ifdef RAL_MAC
#include "Mconsole.h"
#endif // _DEBUG

namespace RAL
{
	class ConsoleFacotry
	{
	public:
		static Console* createConsole();
	};
}
