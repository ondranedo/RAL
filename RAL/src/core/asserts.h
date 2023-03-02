#pragma once

/*
	Asserts WILL abort the program if the given condition is false
	Need to define for both DEBUG and RELEASE
	For RELEASE, define empty macros
*/

#ifdef RAL_DEBUG

#include <cassert>
#include "defines.h"

namespace RAL {
	namespace ASSERTS {
		RAL_API void msg(const char* message);
	}
}

#define RAL_ASSERT_UNREACHABLE(message) RAL::ASSERTS::msg(message); assert(0)
#define RAL_ASSERT_NEGATIVE(point, message) RAL::ASSERTS::msg(message); assert(reinterpret_cast<int>(point) >= 0)
#define RAL_ASSERT(expr, message)) RAL::ASSERTS::msg(message); assert(expr != NULL)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size) static_assert(sizeof(_t) == _t_size)

#endif
#ifdef RAL_RELEASE

#define RAL_ASSERT_UNREACHABLE(message)
#define RAL_ASSERT_NEGATIVE(point, message)
#define RAL_ASSERT(expr, message)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size)

#endif
