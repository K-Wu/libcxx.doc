//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// test ratio_add

#include <ratio.hxx>

int main(int, char**)
{
    typedef std::ratio<0x7FFFFFFFFFFFFFFFLL, 1> R1;
    typedef std::ratio<1, 1> R2;
    typedef std::ratio_add<R1, R2>::type R;

  return 0;
}
