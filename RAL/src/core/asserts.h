#pragma once
#include "../pch.h"
/*
	Asserts WILL abort the program if the given condition is false
	Need to define for both DEBUG and RELEASE
	For RELEASE, define empty macros
*/

#ifdef RAL_DEBUG

#include <cassert>

#define RAL_ASSERT_MSG(...)\
            RAL_LOG_CRIT("ASSERTION AT %s:%d ", __FILE__, __LINE__);\
            RAL_LOG_CRIT(__VA_ARGS__);


#define RAL_ASSERT_UNREACHABLE(...) RAL_ASSERT_MSG(__VA_ARGS__)
#define RAL_ASSERT_NEGATIVE(point,...) if(((int)point)<0) {RAL_ASSERT_MSG(__VA_ARGS__);}
#define RAL_ASSERT_NULL(point,...) if(reinterpret_cast<void*>(point)==static_cast<void*>(0)) {RAL_ASSERT_MSG(__VA_ARGS__);}
#define RAL_ASSERT(expr, ...) if(!(expr)) {RAL_ASSERT_MSG(__VA_ARGS__);}
#define RAL_ASSERT_DATA_TYPE(_t,_t_size) static_assert(sizeof(_t) == _t_size)


#else

#define RAL_ASSERT_UNREACHABLE(message)
#define RAL_ASSERT_NEGATIVE(point, message)
#define RAL_ASSERT_NULL(point,...)
#define RAL_ASSERT(expr, message)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size)

#endif //!RAL_DEBUG