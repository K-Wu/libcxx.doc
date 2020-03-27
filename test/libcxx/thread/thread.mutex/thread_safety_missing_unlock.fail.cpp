//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// On Windows Clang bugs out when both __declspec and __attribute__ are present,
// the processing goes awry preventing the definition of the types.
// XFAIL: LIBCXX-WINDOWS-FIXME

// UNSUPPORTED: libcpp-has-no-threads
// REQUIRES: thread-safety

// <mutex>

// MODULES_DEFINES: _LIBCPP_ENABLE_THREAD_SAFETY_ANNOTATIONS
#define _LIBCPP_ENABLE_THREAD_SAFETY_ANNOTATIONS

#include <mutex.hxx>

std::mutex m;

int main(int, char**) {
  m.lock();

  return 0;
} // expected-error {{mutex 'm' is still held at the end of function}}
