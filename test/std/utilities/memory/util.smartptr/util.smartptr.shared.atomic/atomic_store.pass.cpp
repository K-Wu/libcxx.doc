//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads
//
// This test uses new symbols that were not defined in the libc++ shipped on
// darwin11 and darwin12:
// XFAIL: availability=macosx10.7
// XFAIL: availability=macosx10.8

// <memory>

// shared_ptr

// template <class T>
// void
// atomic_store(shared_ptr<T>* p, shared_ptr<T> r)

// UNSUPPORTED: c++98, c++03

#include <memory.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        std::shared_ptr<int> p;
        std::shared_ptr<int> r(new int(3));
        std::atomic_store(&p, r);
        assert(*p == *r);
    }

  return 0;
}
