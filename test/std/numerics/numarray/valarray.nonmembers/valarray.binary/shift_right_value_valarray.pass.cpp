//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T> valarray<T> operator>>(const T& x, const valarray<T>& y);

#include <valarray.hxx>
#include <cassert.hxx>
#include <cstddef.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        typedef int T;
        T a1[] = { 1,   2,  3,  4,  5};
        T a2[] = {20,  10,  5,  2,  1};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<T> v2 = 40 >> v1;
        assert(v1.size() == v2.size());
        for (std::size_t i = 0; i < v2.size(); ++i)
            assert(v2[i] == a2[i]);
    }

  return 0;
}
