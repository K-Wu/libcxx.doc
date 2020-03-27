//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// This test ensures that std::tuple<> is trivially constructible. That is not
// required by the Standard, but libc++ provides that guarantee.

// UNSUPPORTED: c++98, c++03

#include <tuple.hxx>
#include <type_traits.hxx>


static_assert(std::is_trivially_constructible<std::tuple<>>::value, "");

int main(int, char**) {
  return 0;
}
