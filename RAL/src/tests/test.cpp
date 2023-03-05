#include "test.h"
#include "core/defines.h"
#include "core/logger.h"
#include "core/types.h"
#include "core/asserts.h"
#include "platformLayer/console/console.h"
#define RAL_DEBUG
namespace RAL {
	void test_all()
	{
#ifdef RAL_DEBUG
		RAL_LOG_PRIORITY_DEBUG();
		test_console();
		test_linkage();
		system("pause");
		RAL_LOG_PRIORITY_PREVIOUS();
#endif //RAL_DEBUG
	}


	// Testing linkage
	void test_linkage()
	{
		RAL_LOG_DEBUG("[TEST] RAL linkage");
	}

	void test_data_types()
	{
		RAL_ASSERT_DATA_TYPE(u8_t,  1);
		RAL_ASSERT_DATA_TYPE(u16_t, 2);
		RAL_ASSERT_DATA_TYPE(u32_t, 4);
		RAL_ASSERT_DATA_TYPE(u64_t, 8);
		RAL_ASSERT_DATA_TYPE(i8_t,  1);
		RAL_ASSERT_DATA_TYPE(i16_t, 2);
		RAL_ASSERT_DATA_TYPE(i32_t, 4);
		RAL_ASSERT_DATA_TYPE(i64_t, 8);
		RAL_ASSERT_DATA_TYPE(f32_t, 4);
		RAL_ASSERT_DATA_TYPE(f64_t, 8);
		RAL_LOG_DEBUG("[TEST] Data types - excepted size");
	}

	void test_console()
	{	
		RAL::Console* console = RAL::ConsoleFacotry::createConsole();
		console->setTitle("Test");
		console->log("Ahojda",Console::BG_YELLOW,Console::FG_BLUE);
	}

}

