#include <windows.h>
#include <string>

#if (defined(__cplusplus) && __cplusplus == 201103L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
#define CPP11 1 // the compiler has support for C++11
#endif

#ifdef _EXPORT
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

namespace grv
{
	// Integer typedefs
	typedef char s8;
	typedef unsigned char u8;
	typedef short s16;
	typedef unsigned short u16;
	typedef int s32;
	typedef unsigned int u32;
	typedef long long s64;
	typedef unsigned long long u64;

	// Float typedefs
	typedef float f32;
	typedef double f64;

	// String typedefs
	typedef std::string str;
}
