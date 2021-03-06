//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <memory.hxx>
#include <string.hxx>
#include <cassert.hxx>

int main(int, char**)
{
    auto up4 = std::make_unique<int[5]>(11, 22, 33, 44, 55); // deleted

  return 0;
}
