//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <thread>

// class thread::id

// template<class charT, class traits>
// basic_ostream<charT, traits>&
// operator<<(basic_ostream<charT, traits>& out, thread::id id);

#include <thread.hxx>
#include <sstream.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    std::thread::id id0 = std::this_thread::get_id();
    std::ostringstream os;
    os << id0;

  return 0;
}
