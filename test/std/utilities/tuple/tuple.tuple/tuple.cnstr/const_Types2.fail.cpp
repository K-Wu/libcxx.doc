//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <tuple>

// template <class... Types> class tuple;

// explicit tuple(const T&...);

// UNSUPPORTED: c++98, c++03

#include <tuple.hxx>
#include <string.hxx>
#include <cassert.hxx>

int main(int, char**)
{
    {
        std::tuple<int, char*, std::string, double&> t(2, nullptr, "text");
    }

  return 0;
}
