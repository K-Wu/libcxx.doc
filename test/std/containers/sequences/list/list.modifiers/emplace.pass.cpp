//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03

// <list>

// template <class... Args> void emplace(const_iterator p, Args&&... args);


#include <list.hxx>
#include <cassert.hxx>

#include "test_macros.h"
#include "min_allocator.h"

class A
{
    int i_;
    double d_;

    A(const A&);
    A& operator=(const A&);
public:
    A(int i, double d)
        : i_(i), d_(d) {}

    int geti() const {return i_;}
    double getd() const {return d_;}
};

int main(int, char**)
{
    {
    std::list<A> c;
    c.emplace(c.cbegin(), 2, 3.5);
    assert(c.size() == 1);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    c.emplace(c.cend(), 3, 4.5);
    assert(c.size() == 2);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    assert(c.back().geti() == 3);
    assert(c.back().getd() == 4.5);
    }
    {
    std::list<A, min_allocator<A>> c;
    c.emplace(c.cbegin(), 2, 3.5);
    assert(c.size() == 1);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    c.emplace(c.cend(), 3, 4.5);
    assert(c.size() == 2);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    assert(c.back().geti() == 3);
    assert(c.back().getd() == 4.5);
    }


  return 0;
}
