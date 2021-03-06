//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <semaphore>

#include <semaphore.hxx>
#include <thread.hxx>

#include "test_macros.h"

int main(int, char**)
{
  std::counting_semaphore<> s(0);
  
  s.release();
  s.acquire();

  std::thread t([&](){ 
    s.acquire();
  });
  s.release(2);
  t.join();
  s.acquire();

  return 0;
}
