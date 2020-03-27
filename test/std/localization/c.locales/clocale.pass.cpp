//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <clocale>

#include <clocale.hxx>
#include <type_traits.hxx>

#include "test_macros.h"

#ifndef _LIBCPP_HAS_NO_THREAD_UNSAFE_C_FUNCTIONS

#ifndef LC_ALL
#error LC_ALL not defined
#endif

#ifndef LC_COLLATE
#error LC_COLLATE not defined
#endif

#ifndef LC_CTYPE
#error LC_CTYPE not defined
#endif

#ifndef LC_MONETARY
#error LC_MONETARY not defined
#endif

#ifndef LC_NUMERIC
#error LC_NUMERIC not defined
#endif

#ifndef LC_TIME
#error LC_TIME not defined
#endif

#endif // !_LIBCPP_HAS_NO_THREAD_UNSAFE_C_FUNCTIONS

#ifndef NULL
#error NULL not defined
#endif

int main(int, char**)
{
    std::lconv lc;
    ((void)lc); // Prevent unused warning
#ifndef _LIBCPP_HAS_NO_THREAD_UNSAFE_C_FUNCTIONS
    static_assert((std::is_same<decltype(std::setlocale(0, "")), char*>::value), "");
#endif
    static_assert((std::is_same<decltype(std::localeconv()), std::lconv*>::value), "");

  return 0;
}
