//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <locale>

// class locale;

// explicit locale( const char* std_name );

// REQUIRES: libcpp-no-exceptions

// Make sure we abort() when we construct a locale with a null name and
// exceptions are disabled.

#include <csignal.hxx>
#include <cstdlib.hxx>
#include <locale.hxx>

#include "test_macros.h"


void exit_success(int) {
    std::_Exit(EXIT_SUCCESS);
}

int main(int, char**) {
    std::signal(SIGABRT, exit_success);
    std::locale loc(NULL);
    (void)loc;
    return EXIT_FAILURE;
}
