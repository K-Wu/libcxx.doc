//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char32_t>

// static char_type* copy(char_type* s1, const char_type* s2, size_t n);

#include <string.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    char32_t s1[] = {1, 2, 3};
    char32_t s2[3] = {0};
    assert(std::char_traits<char32_t>::copy(s2, s1, 3) == s2);
    assert(s2[0] == char32_t(1));
    assert(s2[1] == char32_t(2));
    assert(s2[2] == char32_t(3));
    assert(std::char_traits<char32_t>::copy(NULL, s1, 0) == NULL);
    assert(std::char_traits<char32_t>::copy(s1, NULL, 0) == s1);
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS

  return 0;
}
