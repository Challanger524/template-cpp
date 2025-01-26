#pragma once

/** Project's main configuration (precompiled) header - force included into all source files
 *  Should be included via file:///./../CMakeLists.txt: `target_precompile_headers()`
 *  Intellisense hint option should be present:
 *    **VS Code**
 *      - in file:///./../.vscode/c_cpp_properties.json via opt "forcedInclude"
 *      - or file:///./../.vscode/settings.json         via opt "C_Cpp.default.forcedInclude" (works if no .code-workspace)
 *      - or file:///./../template-cpp.code-workspace   via opt "C_Cpp.default.forcedInclude"
 *
 *  How to remove this PCH (precompiled header) - simply comment out:
 *    - file:///./../CMakeLists.txt : `target_precompile_headers(...)`         line
 *    - file:///./main.cpp          : `#error "config.hpp" not force included` line
 */

#ifndef PROJECT_CONFIG_PCH
#define PROJECT_CONFIG_PCH // `config.hpp` presence definition mark
#endif


//------------------------ Includes -------------------------------------------


// #include <conf/imconfig.h> // project config for Dear ImGui

#ifdef _WIN32
#include <SDKDDKVer.h>      // for assembling (boost::context,..)
#endif


//------------------------ Defines --------------------------------------------


#if (!defined(NDEBUG) || defined(TESTS_IN_APP)) && !defined(NO_TESTS_IN_APP)
#  ifndef TESTING
#    define TESTING
#  endif
#endif


//------------------------ Macro functions ------------------------------------


#define  STR(X) #X     // stringizie the `X` (macro) _identifier_
#define MSTR(E) STR(E) // stringizie the `E`  macro  _expression_

// https://stackoverflow.com/questions/154136/why-use-apparently-meaningless-do-while-and-if-else-statements-in-macros
#ifndef  NDEBUG
#define ONDEBUG(E) do { E; } while(0) // `E` exression on debug -  enabled
#else
#define ONDEBUG(E)                    // `E` exression on debug - disabled
#endif

// Compiler-friendly debug breakpoints (in source code)
// https://stackoverflow.com/questions/173618/is-there-a-portable-equivalent-to-debugbreak-debugbreak/49079078#49079078
// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p2514r0.html#_implementation_experience
#ifdef NDEBUG
#  define BREAKPOINT()
#endif

#if !defined(BREAKPOINT) && __has_include(<intrin.h>) && (defined(_MSC_VER) || defined (__MINGW32__))
#  include <intrin.h>
#  define BREAKPOINT() __debugbreak()
#elif defined(__has_builtin) && !defined(__ibmxl__) // clang/gcc
#  if __has_builtin(__builtin_debugtrap) // clang
#    define BREAKPOINT() __builtin_debugtrap()
//#  elif __has_builtin(__builtin_trap) // gcc
//#    define BREAKPOINT() __builtin_trap() // not much useful
#  endif
#endif
#if !defined(BREAKPOINT) && __has_include(<signal.h>)
#  include <signal.h>
#  if defined(SIGTRAP)
#    define BREAKPOINT() raise(SIGTRAP)
#  else
#    define BREAKPOINT() raise(SIGABRT)
#  endif
#endif

#ifndef  NDEBUG
#define ASSERT(E) if (!(E)) BREAKPOINT() // debug breakpoint on `expression` fail -  enabled
#else
#define ASSERT(E)                        // debug breakpoint on `expression` fail - disabled
#endif

//------------------------ Namespaces and typedefs ----------------------------


//namespace      ImGui {} // Dear ImGui namespace pre-declaration (to alias it)
//namespace im = ImGui;   // (global) namespace alias for `ImGui::`

/*                   // https://stackoverflow.com/a/13642921/11753532 // cstdint: std::<type>_t, thx but no.
#include <cstdint>*/ // including `cstdint`   imports the symbol names in std    namespace and possibly in global namespace.
#include <stdint.h>  // including  `stdint.h` imports the symbol names in global namespace and possibly in std    namespace.
using ldouble =          long double;
using llong   =          long long  ;
#ifndef __USE_MISC // ubuntu/gcc lib pollutes global namespace
using ulong   = unsigned long long  ;
using ushort  = unsigned short      ;
using uint    = unsigned int        ;
#endif
using uchar   = unsigned char       ;
using schar   =   signed char       ;

//using money_t = long double; // should be replaced with `moneycpp` lib: https://github.com/mariusbancila/moneycpp


//------------------------ Re-#defines ----------------------------------------


//#define elif else if

//#define ccast       const_cast
  #define scast      static_cast
//#define dcast     dynamic_cast
//#define rcast reinterpret_cast


//------------------------ Options and modifications --------------------------


//#define LIB_LIBCONFIG      // <some define>
//#define MOD_OSTREAM_CHAR8T // enable `char8_t`/`std::u8string` stream `operator<<` overloads

// https://stackoverflow.com/questions/2324658/how-to-determine-the-version-of-the-c-standard-used-by-the-compiler
#if __cplusplus < 2023'00L // MSVC `/Zc:__cplusplus` flag needed for valid `__cplusplus` value
constexpr size_t operator ""uz(unsigned long long n) { return n; } // MSVC C++23 (might) still has no size_t literal (since C++23)
#endif

#if defined(MOD_OSTREAM_CHAR8T) && !defined(NO_MOD_OSTREAM_CHAR8T) // char8_t (since C++20)
#include <iostream>
#include <string>
inline std::ostream &operator<<(std::ostream &os,            char8_t   v) { return os <<      static_cast<      char  >(v        ); }
inline std::ostream &operator<<(std::ostream &os, const      char8_t  *v) { return os << reinterpret_cast<const char *>(v        ); }
inline std::ostream &operator<<(std::ostream &os, const std::u8string &v) { return os << reinterpret_cast<const char *>(v.c_str()); }
#endif
