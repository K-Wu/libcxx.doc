//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <functional>

// reference_wrapper

// reference_wrapper(T& t);

#include <functional.hxx>
#include <cassert.hxx>

#include "test_macros.h"

class functor1
{
};

template <class T>
void
test(T& t)
{
    std::reference_wrapper<T> r(t);
    assert(&r.get() == &t);
}

void f() {}

int main(int, char**)
{
    void (*fp)() = f;
    test(fp);
    test(f);
    functor1 f1;
    test(f1);
    int i = 0;
    test(i);
    const int j = 0;
    test(j);

  return 0;
}
