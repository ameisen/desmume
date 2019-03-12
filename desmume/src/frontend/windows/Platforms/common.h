#pragma once

#if _WIN32
#	include "Platforms/Windows/common.h"
#else
#	error Unsupported Platform
#endif

#ifdef _MSC_VER
#	define _assume(expr) __assume(expr)
#	define _unreachable() __assume(0)
#	define _expect(expr, value) (expr)
#	define _unlikely(expr) (expr)
#	define _likely(expr) (expr)
#	define _unpredictable(expr) (expr)
#elif defined(__clang__)
#	define _assume(expr) __builtin_assume(expr)
#	define _unreachable() __builtin_unreachable()
#	define _expect(expr, value) (__builtin_expect((expr), (value)))
#	define _unlikely(expr) _expect(!!(expr), false)
#	define _likely(expr) _expect(!!(expr), true)
#	define _unpredictable(expr) (__builtin_unpredictable(expr))
#elif defined(__GNUC__)
#	define _assume(expr) do { if (!(expr)) __builtin_unreachable(); } while (0)
#	define _unreachable() __builtin_unreachable()
#	define _expect(expr, value) (__builtin_expect((expr), (value)))
#	define _unlikely(expr) _expect(!!(expr), false)
#	define _likely(expr) _expect(!!(expr), true)
#	define _unpredictable(expr) (__builtin_expect_with_probability((expr), (value), 0.5f))
#else
#	error Unknown Platform
#endif
