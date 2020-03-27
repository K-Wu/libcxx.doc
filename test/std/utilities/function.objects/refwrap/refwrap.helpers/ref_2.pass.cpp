//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <functional>

// reference_wrapper

// template <ObjectType T> reference_wrapper<T> ref(reference_wrapper<T>t);

#include <functional.hxx>
#include <cassert.hxx>

#include "counting_predicates.h"

#include "test_macros.h"

bool is5 ( int i ) { return i == 5; }

template <typename T>
bool call_pred ( T pred ) { return pred(5); }

int main(int, char**)
{
    {
    int i = 0;
    std::reference_wrapper<int> r1 = std::ref(i);
    std::reference_wrapper<int> r2 = std::ref(r1);
    assert(&r2.get() == &i);
    }
    {
    unary_counting_predicate<bool(*)(int), int> cp(is5);
    assert(!cp(6));
    assert(cp.count() == 1);
    assert(call_pred(cp));
    assert(cp.count() == 1);
    assert(call_pred(std::ref(cp)));
    assert(cp.count() == 2);
    }

  return 0;
}
