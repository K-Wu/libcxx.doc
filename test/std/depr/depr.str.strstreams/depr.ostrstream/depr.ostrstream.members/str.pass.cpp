//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <strstream>

// class ostrstream

// char* str();

#include <strstream.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        std::ostrstream out;
        out << 123 << ' ' << 4.5 << ' ' << "dog" << std::ends;
        assert(out.str() == std::string("123 4.5 dog"));
        out.freeze(false);
    }

  return 0;
}
