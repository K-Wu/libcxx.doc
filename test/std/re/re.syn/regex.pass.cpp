//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <regex>

// typedef basic_regex<char>    regex;

#include <regex.hxx>
#include <type_traits.hxx>
#include "test_macros.h"

int main(int, char**)
{
    static_assert((std::is_same<std::basic_regex<char>, std::regex>::value), "");

  return 0;
}
