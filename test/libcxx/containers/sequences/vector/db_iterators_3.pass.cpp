//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <vector>

// Subtract iterators from different containers.

#if _LIBCPP_DEBUG >= 1

#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <vector.hxx>
#include <cassert.hxx>
#include <iterator.hxx>
#include <exception.hxx>
#include <cstdlib.hxx>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    typedef int T;
    typedef std::vector<T> C;
    C c1;
    C c2;
    int i = c1.begin() - c2.begin();
    assert(false);
    }
#if TEST_STD_VER >= 11
    {
    typedef int T;
    typedef std::vector<T, min_allocator<T>> C;
    C c1;
    C c2;
    int i = c1.begin() - c2.begin();
    assert(false);
    }
#endif
}

#else

int main(int, char**)
{

  return 0;
}

#endif
