//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iomanip>

// T6 setw(int n);

#include <iomanip.hxx>
#include <istream.hxx>
#include <ostream.hxx>
#include <cassert.hxx>

#include "test_macros.h"

template <class CharT>
struct testbuf
    : public std::basic_streambuf<CharT>
{
    testbuf() {}
};

int main(int, char**)
{
    {
        testbuf<char> sb;
        std::istream is(&sb);
        is >> std::setw(10);
        assert(is.width() == 10);
    }
    {
        testbuf<char> sb;
        std::ostream os(&sb);
        os << std::setw(10);
        assert(os.width() == 10);
    }
    {
        testbuf<wchar_t> sb;
        std::wistream is(&sb);
        is >> std::setw(10);
        assert(is.width() == 10);
    }
    {
        testbuf<wchar_t> sb;
        std::wostream os(&sb);
        os << std::setw(10);
        assert(os.width() == 10);
    }

  return 0;
}
