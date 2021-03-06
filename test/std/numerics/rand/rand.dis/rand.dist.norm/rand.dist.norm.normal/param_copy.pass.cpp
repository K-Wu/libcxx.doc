//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class normal_distribution
// {
//     class param_type;

#include <random.hxx>
#include <limits.hxx>
#include <cassert.hxx>

#include "test_macros.h"

int main(int, char**)
{
    {
        typedef std::normal_distribution<> D;
        typedef D::param_type param_type;
        param_type p0(10, .125);
        param_type p = p0;
        assert(p.mean() == 10);
        assert(p.stddev() == .125);
    }

  return 0;
}
