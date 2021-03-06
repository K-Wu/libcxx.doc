//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++98, c++03, c++11, c++14, c++17

// <chrono>
// class day;

#include <chrono.hxx>
#include <type_traits.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    using day = std::chrono::day;

    static_assert(std::is_trivially_copyable_v<day>, "");
    static_assert(std::is_standard_layout_v<day>, "");

  return 0;
}
