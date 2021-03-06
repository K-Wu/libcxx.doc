//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// test invalid_argument

#include <stdexcept.hxx>
#include <type_traits.hxx>
#include <cstring.hxx>
#include <string.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    static_assert((std::is_base_of<std::logic_error, std::invalid_argument>::value),
                 "std::is_base_of<std::logic_error, std::invalid_argument>::value");
    static_assert(std::is_polymorphic<std::invalid_argument>::value,
                 "std::is_polymorphic<std::invalid_argument>::value");
    {
    const char* msg = "invalid_argument message";
    std::invalid_argument e(msg);
    assert(std::strcmp(e.what(), msg) == 0);
    std::invalid_argument e2(e);
    assert(std::strcmp(e2.what(), msg) == 0);
    e2 = e;
    assert(std::strcmp(e2.what(), msg) == 0);
    }
    {
    std::string msg("another invalid_argument message");
    std::invalid_argument e(msg);
    assert(e.what() == msg);
    std::invalid_argument e2(e);
    assert(e2.what() == msg);
    e2 = e;
    assert(e2.what() == msg);
    }

  return 0;
}
