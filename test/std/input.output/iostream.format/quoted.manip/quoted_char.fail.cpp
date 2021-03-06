//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iomanip>

// quoted

#include <iomanip.hxx>
#include <sstream.hxx>
#include <string.hxx>
#include <cassert.hxx>

#include "test_macros.h"

//  Test that mismatches between strings and wide streams are diagnosed

#if TEST_STD_VER > 11

void round_trip ( const char *p ) {
    std::wstringstream ss;
    ss << std::quoted(p);
    std::string s;
    ss >> std::quoted(s);
    }



int main(int, char**)
{
    round_trip ( "Hi Mom" );
}
#else
#error
#endif
