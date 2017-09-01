/** @file main.cpp
 * Just a simple hello world using libfmt
 */
// The previous block is needed in every file for which you want to generate documentation

#include <fmt/format.h>

// Based on: https://stackoverflow.com/a/36175016
#define DIAG_STR(s) #s
#define DIAG_JOINSTR(x,y) DIAG_STR(x ## y)

#ifdef _MSC_VER
#define DIAG_DO_PRAGMA(x) __pragma (#x)
#define DIAG_PRAGMA(compiler,x) DIAG_DO_PRAGMA(warning(x))
#else
#define DIAG_DO_PRAGMA(x) _Pragma (#x)
#define DIAG_PRAGMA(compiler,x) DIAG_DO_PRAGMA(compiler diagnostic x)
#endif

#if defined(__GNUC__)
	#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406
		#define DISABLE_WARNING_GCC(gcc_option) DIAG_PRAGMA(GCC,push) DIAG_PRAGMA(GCC,ignored DIAG_JOINSTR(-W,gcc_option))
		#define ENABLE_WARNING_GCC(gcc_option)  DIAG_PRAGMA(GCC,pop)
	#else
		#define DISABLE_WARNING_GCC(gcc_option) DIAG_PRAGMA(GCC,ignored DIAG_JOINSTR(-W,gcc_option))
		#define ENABLE_WARNING_GCC(gcc_option)  DIAG_PRAGMA(GCC,warning DIAG_JOINSTR(-W,gcc_option))
	#endif
	#define DISABLE_WARNING_CLANG(x)
	#define ENABLE_WARNING_CLANG(x)
	#define DISABLE_WARNING_MSVC(x)
	#define ENABLE_WARNING_MSVC(x)
#elif defined(__clang__)
	#define ENABLE_WARNING_CLANG(clang_option) DIAG_PRAGMA(clang,push) DIAG_PRAGMA(clang,ignored DIAG_JOINSTR(-W,clang_option))
	#define ENABLE_WARNING_CLANG(clang_option) DIAG_PRAGMA(clang,pop)
	#define DISABLE_WARNING_GCC(x)
	#define ENABLE_WARNING_GCC(x)
	#define DISABLE_WARNING_MSVC(x)
	#define ENABLE_WARNING_MSVC(x)
#elif defined(_MSC_VER)
	#define ENABLE_WARNING_MSVC(msvc_errorcode)  DIAG_PRAGMA(msvc,push) DIAG_DO_PRAGMA(warning(disable:##msvc_errorcode))
	#define DISABLE_WARNING_MSVC(msvc_errorcode) DIAG_PRAGMA(msvc,pop)
	#define DISABLE_WARNING_GCC(x)
	#define ENABLE_WARNING_GCC(x)
	#define DISABLE_WARNING_CLANG(x)
	#define ENABLE_WARNING_CLANG(x)
#endif

#if defined(__GNUC__)
	#define DISABLE_WARNING(gcc_unused,clang_option,msvc_unused) DISABLE_WARNING_GCC(gcc_unused)
	#define ENABLE_WARNING(gcc_unused,clang_option,msvc_unused)  ENABLE_WARNING_GCC(gcc_unused)
#elif defined(__clang__)
	#define DISABLE_WARNING(gcc_unused,clang_option,msvc_unused) DISABLE_WARNING_CLANG(clang_option)
	#define ENABLE_WARNING(gcc_unused,clang_option,msvc_unused)  ENABLE_WARNING_CLANG(clang_option)
#elif defined(_MSC_VER)
	#define DISABLE_WARNING(gcc_unused,clang_unused,msvc_errorcode) DISABLE_WARNING_MSVC(msvc_errorcode)
	#define ENABLE_WARNING(gcc_unused,clang_unused,msvc_errorcode)  ENABLE_WARNING_MSVC(msvc_errorcode)
#endif

DISABLE_WARNING(ignored-qualifiers, ignored-qualifiers, 0)
DISABLE_WARNING(sign-conversion, sign-conversion, 0)
DISABLE_WARNING(sign-conversion, sign-conversion, 0)

DISABLE_WARNING_MSVC(4201) // Nameless struct/union
DISABLE_WARNING_MSVC(4309) // 'static_cast': truncation of constant value
DISABLE_WARNING_MSVC(4458) // Declaration of 'x' hides class member
DISABLE_WARNING_MSVC(4100) // Unreferenced formal parameter

DISABLE_WARNING_GCC(pedantic)
DISABLE_WARNING_GCC(ignored-qualifiers)
DISABLE_WARNING_GCC(type-limits)

DISABLE_WARNING_CLANG(sign-conversion)
DISABLE_WARNING_CLANG(ignored-qualifiers)
DISABLE_WARNING_CLANG(shadow-field-in-constructor)
DISABLE_WARNING_CLANG(shadow)

#include <gli/gli.hpp>

ENABLE_WARNING_MSVC(4201) // Nameless struct/union
ENABLE_WARNING_MSVC(4309) // 'static_cast': truncation of constant value
ENABLE_WARNING_MSVC(4458) // Declaration of 'x' hides class member
ENABLE_WARNING_MSVC(4100) // Unreferenced formal parameter

ENABLE_WARNING_GCC(pedantic)
ENABLE_WARNING_GCC(ignored-qualifiers)
ENABLE_WARNING_GCC(type-limits)

ENABLE_WARNING_CLANG(sign-conversion)
ENABLE_WARNING_CLANG(ignored-qualifiers)
ENABLE_WARNING_CLANG(shadow-field-in-constructor)
ENABLE_WARNING_CLANG(shadow)

// This should be in the headers

/**
 * @brief A function that does nothing but generate documentation
 * @return The answer to life, the universe and everything
 */
int foo();

int main(int argc, char* argv[])
{
    if (argc)
    {
        fmt::print("hello world from {}!", argv[0]);
    }
    return 0;
}

// Implementation
int foo() { return 42; }
