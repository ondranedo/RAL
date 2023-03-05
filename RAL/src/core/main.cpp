#include "defines.h"
#include "tests/test.h"
#include "application.h"
#include "logger.h"
#include "baseGame.h"

#include "../containers/string.h"

int main()
{
	RAL_LOG_PRIORITY_TRACE();

	RAL::String s1 = "Hello";
	RAL::String s3 = "World!";
	RAL::String s4 = s1 + ' ' + s3[0];

	RAL_LOG_INFO("STRING >%s<", s4.c_str());
}