//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <barrier>

#include <barrier.hxx>
#include <thread.hxx>

#include "test_macros.h"

int main(int, char**)
{
  std::barrier<> b(2);
  
  std::thread t([&](){ 
    for(int i = 0; i < 10; ++i)
      b.arrive_and_wait(); 
  });
  for(int i = 0; i < 10; ++i)
    b.arrive_and_wait();
  t.join();

  return 0;
}
