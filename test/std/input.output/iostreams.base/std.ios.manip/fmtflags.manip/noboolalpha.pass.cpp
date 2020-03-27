//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// ios_base& noboolalpha(ios_base& str);

#include <ios.hxx>
#include <streambuf.hxx>
#include <cassert.hxx>

#include "test_macros.h"

struct testbuf : public std::streambuf {};

int main(int, char**)
{
    testbuf sb;
    std::ios ios(&sb);
    std::boolalpha(ios);
    std::ios_base& r = std::noboolalpha(ios);
    assert(&r == &ios);
    assert(!(ios.flags() & std::ios::boolalpha));

  return 0;
}
