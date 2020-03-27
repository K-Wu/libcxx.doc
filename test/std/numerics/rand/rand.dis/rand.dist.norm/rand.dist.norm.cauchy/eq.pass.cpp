//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class cauchy_distribution

// bool operator=(const cauchy_distribution& x,
//                const cauchy_distribution& y);
// bool operator!(const cauchy_distribution& x,
//                const cauchy_distribution& y);

#include <random.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        typedef std::cauchy_distribution<> D;
        D d1(2.5, 4);
        D d2(2.5, 4);
        assert(d1 == d2);
    }
    {
        typedef std::cauchy_distribution<> D;
        D d1(2.5, 4);
        D d2(2.5, 4.5);
        assert(d1 != d2);
    }

  return 0;
}
