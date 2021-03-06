//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class Alloc>
// struct allocator_traits
// {
//     typedef typename Alloc::value_type value_type;
//     ...
// };

#include <memory.hxx>
#include <type_traits.hxx>

#include "test_macros.h"

template <class T>
struct A
{
    typedef T value_type;
};

int main(int, char**)
{
    static_assert((std::is_same<std::allocator_traits<A<char> >::value_type, char>::value), "");

  return 0;
}
