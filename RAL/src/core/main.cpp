#include "defines.h"
#include "tests/test.h"
#include "application.h"
#include "logger.h"
#include "baseGame.h"

RAL_API int main()
{
	RAL_LOG_PRIORITY_TRACE();
	RAL::test_all();

	auto app = RAL::createBaseGame();
	app->call();
	delete app;
}