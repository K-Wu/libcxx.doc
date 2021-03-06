//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// value_type min() const;

#include <valarray.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        typedef double T;
        T a1[] = {1.5, 2.5, -3, 4, 5.5};
        const unsigned N1 = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N1);
        assert(v1.min() == -3.0);
    }
    {
        typedef double T;
        std::valarray<T> v1;
        v1.min();
    }
    {
        typedef double T;
        T a1[] = {1.5, 2.5, -3, 4, 5.5};
        const unsigned N1 = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N1);
        assert((2*v1).min() == -6.0);
    }

  return 0;
}
