//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset

// size_type bucket(const key_type& __k) const;

#ifdef _LIBCPP_DEBUG
#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))
#endif

#include <unordered_set.hxx>
#include <cassert.hxx>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
        typedef std::unordered_multiset<int> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        const C c(std::begin(a), std::end(a));
        size_t bc = c.bucket_count();
        assert(bc >= 7);
        for (size_t i = 0; i < 13; ++i)
            LIBCPP_ASSERT(c.bucket(i) == i % bc);
    }
#if TEST_STD_VER >= 11
    {
        typedef std::unordered_multiset<int, std::hash<int>,
                                      std::equal_to<int>, min_allocator<int>> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        const C c(std::begin(a), std::end(a));
        size_t bc = c.bucket_count();
        assert(bc >= 7);
        for (size_t i = 0; i < 13; ++i)
            LIBCPP_ASSERT(c.bucket(i) == i % bc);
    }
#endif
#if _LIBCPP_DEBUG_LEVEL >= 1
    {
        typedef std::unordered_multiset<int> C;
        C c;
        (void) c.bucket(3);
        assert(false);
    }
#endif

  return 0;
}
