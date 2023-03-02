#include "test.h"
#include "core/defines.h"
#include "core/logger.h"
#include "core/types.h"
#include "core/asserts.h"

namespace RAL {
	RAL_API void test_all()
	{
#ifdef RAL_DEBUG
		RAL_LOG_PRIORITY_DEBUG();
		test_linkage();
		test_data_types();
		RAL_LOG_PRIORITY_PREVIOUS();
#endif //RAL_DEBUG
	}


	// Testing linkage
	RAL_API void test_linkage()
	{
		RAL_LOG_DEBUG("[TEST] RAL linkage");
	}

	RAL_API void test_data_types()
	{
		RAL_ASSERT_DATA_TYPE(u8_t, 1);
		RAL_ASSERT_DATA_TYPE(u16_t, 2);
		RAL_ASSERT_DATA_TYPE(u32_t, 4);
		RAL_ASSERT_DATA_TYPE(u64_t, 8);
		RAL_ASSERT_DATA_TYPE(i8_t, 1);
		RAL_ASSERT_DATA_TYPE(i16_t, 2);
		RAL_ASSERT_DATA_TYPE(i32_t, 4);
		RAL_ASSERT_DATA_TYPE(i64_t, 8);
		RAL_ASSERT_DATA_TYPE(f32_t, 4);
		RAL_ASSERT_DATA_TYPE(f64_t, 8);
		RAL_LOG_DEBUG("[TEST] Data types - excepted size");
	}

}

