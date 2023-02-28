#pragma once

#ifdef RAL_EXPORT
#define RAL_API __declspec(dllexport)
#else
#define RAL_API __declspec(dllimport)
#endif