//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class uniform_real_distribution

// bool operator=(const uniform_real_distribution& x,
//                const uniform_real_distribution& y);
// bool operator!(const uniform_real_distribution& x,
//                const uniform_real_distribution& y);

#include <random.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        typedef std::uniform_real_distribution<> D;
        D d1(3, 8);
        D d2(3, 8);
        assert(d1 == d2);
    }
    {
        typedef std::uniform_real_distribution<> D;
        D d1(3, 8);
        D d2(3, 8.1);
        assert(d1 != d2);
    }

  return 0;
}
