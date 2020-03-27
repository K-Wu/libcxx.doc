//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// <istream>

// Test the feature test macros defined by <istream>

/*  Constant             Value
    __cpp_lib_char8_t    201811L [C++2a]
*/

#include <istream.hxx>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++2a"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++2a"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++2a"
# endif

#elif TEST_STD_VER > 17

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++2a"
#   endif
#   if __cpp_lib_char8_t != 201811L
#     error "__cpp_lib_char8_t should have the value 201811L in c++2a"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when defined(__cpp_char8_t) is not defined!"
#   endif
# endif

#endif // TEST_STD_VER > 17

int main(int, char**) { return 0; }
