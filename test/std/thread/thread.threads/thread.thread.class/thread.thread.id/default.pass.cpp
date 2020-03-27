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

// id();

#include <thread.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    std::thread::id id;
    assert(id == std::thread::id());

  return 0;
}
