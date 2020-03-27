//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iterator>

// istreambuf_iterator

// charT operator*() const

#include <iterator.hxx>
#include <sstream.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        std::istringstream inf("abc");
        std::istreambuf_iterator<char> i(inf);
        assert(*i == 'a');
        ++i;
        assert(*i == 'b');
        ++i;
        assert(*i == 'c');
    }
    {
        std::wistringstream inf(L"abc");
        std::istreambuf_iterator<wchar_t> i(inf);
        assert(*i == L'a');
        ++i;
        assert(*i == L'b');
        ++i;
        assert(*i == L'c');
    }

  return 0;
}
