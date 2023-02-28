/*
	Asserts WILL abort the program if the given condition is false
	Need to define for both DEBUG and RELEASE
	For RELEASE, define empty macros
*/

#ifdef RAL_DEBUG

#include <cassert>

#define RAL_ASSERT_UNREACHABLE() assert(0)
#define RAL_ASSERT_NEGATIVE(point) assert(point >= 0)
#define RAL_ASSERT(expr) assert(expr != NULL)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size) static_assert(sizeof(_t) == _t_size);

#endif
#ifdef RAL_RELEASE

#define RAL_ASSERT_UNREACHABLE()
#define RAL_ASSERT_NEGATIVE()
#define RAL_ASSERT(expr)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size)

#endif