#include "defines.h"
#include "tests/test.h"
#include "application.h"
#include "logger.h"
#include "baseGame.h"

int main()
{	
	RAL_LOG_PRIORITY_TRACE();
	RAL::test_all();
}