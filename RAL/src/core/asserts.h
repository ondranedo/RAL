#pragma once

/*
	Asserts WILL abort the program if the given condition is false
	Need to define for both DEBUG and RELEASE
	For RELEASE, define empty macros
*/

#ifdef RAL_DEBUG

#include <cassert>
#include "defines.h"
#include "logger.h"

namespace RAL {
	namespace ASSERTS {
		template<typename ...Args>
		void msg(Args... args) {
			RAL_LOG_CRIT("ASSERTION AT %s:%d ", __FILE__, __LINE__);
			RAL_LOG_CRIT(args...);
		}
	}
}
#ifdef _MSC_VER

#define RAL_ASSERT_UNREACHABLE(...) RAL::ASSERTS::msg(__VA_ARGS__); __debugbreak()
#define RAL_ASSERT_NEGATIVE(point,...) if(((int)point)<0) {RAL::ASSERTS::msg(__VA_ARGS__); __debugbreak();}
#define RAL_ASSERT_NULL(point,...) if(((int)point)==0) {RAL::ASSERTS::msg(__VA_ARGS__); __debugbreak();}
#define RAL_ASSERT(expr, ...)) if(!(expr)) {RAL::ASSERTS::msg(__VA_ARGS__); __debugbreak();}
#define RAL_ASSERT_DATA_TYPE(_t,_t_size) static_assert(sizeof(_t) == _t_size)

#else

#define RAL_ASSERT_UNREACHABLE(...) RAL::ASSERTS::msg(__VA_ARGS__); 
#define RAL_ASSERT_NEGATIVE(point,...) if(((int)point)<0) {RAL::ASSERTS::msg(__VA_ARGS__);}
#define RAL_ASSERT_NULL(point,...) if(((int)point)==0) {RAL::ASSERTS::msg(__VA_ARGS__);}
#define RAL_ASSERT(expr, ...)) if(!(expr)) {RAL::ASSERTS::msg(__VA_ARGS__);}
#define RAL_ASSERT_DATA_TYPE(_t,_t_size) static_assert(sizeof(_t) == _t_size)

#endif
#else

#define RAL_ASSERT_UNREACHABLE(message)
#define RAL_ASSERT_NEGATIVE(point, message)
#define RAL_ASSERT(expr, message)
#define RAL_ASSERT_DATA_TYPE(_t,_t_size)

#endif
