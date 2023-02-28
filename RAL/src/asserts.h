/*
	Asserts WILL abort the program if the given condition is false
	Need to define for both DEBUG and RELEASE
	For RELEASE, define empty macros
*/

#ifdef RAL_DEBUG

#include <cassert>

#define RAL_ASSERT_UNREACHABLE() assert(0)
#define RAL_ASSERT_NEGATIVE_INDEX(point) assert(point >= 0)
#define RAL_ASSERT(expr) assert(expr != NULL)

#endif
#ifdef RAL_RELEASE

#define RAL_ASSERT_UNREACHABLE()
#define RAL_ASSERT_NEGATIVE_INDEX()
#define RAL_ASSERT(expr)

#endif