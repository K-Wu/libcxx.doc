// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Test that we can include each header in two TU's and link them together.

// RUN: %compile -fsyntax-only

// Prevent <ext/hash_map> from generating deprecated warnings for this test.
#if defined(__DEPRECATED)
#undef __DEPRECATED
#endif

#define TEST_MACROS() static_assert(min() == true && max() == true, "")
#define min() true
#define max() true

// Top level headers
#include <algorithm.hxx>
TEST_MACROS();
#include <any.hxx>
TEST_MACROS();
#include <array.hxx>
TEST_MACROS();
#ifndef _LIBCPP_HAS_NO_THREADS
#include <atomic.hxx>
TEST_MACROS();
#endif
#include <bitset.hxx>
TEST_MACROS();
#include <cassert.hxx>
TEST_MACROS();
#include <ccomplex.hxx>
TEST_MACROS();
#include <cctype.hxx>
TEST_MACROS();
#include <cerrno.hxx>
TEST_MACROS();
#include <cfenv.hxx>
TEST_MACROS();
#include <cfloat.hxx>
TEST_MACROS();
#include <charconv.hxx>
TEST_MACROS();
#include <chrono.hxx>
TEST_MACROS();
#include <cinttypes.hxx>
TEST_MACROS();
#include <ciso646.hxx>
TEST_MACROS();
#include <climits.hxx>
TEST_MACROS();
#include <clocale.hxx>
TEST_MACROS();
#include <cmath.hxx>
TEST_MACROS();
#include <codecvt.hxx>
TEST_MACROS();
#include <complex.hxx>
TEST_MACROS();
#include <complex.h>
TEST_MACROS();
#include <condition_variable.hxx>
TEST_MACROS();
#include <csetjmp.hxx>
TEST_MACROS();
#include <csignal.hxx>
TEST_MACROS();
#include <cstdarg.hxx>
TEST_MACROS();
#include <cstdbool.hxx>
TEST_MACROS();
#include <cstddef.hxx>
TEST_MACROS();
#include <cstdint.hxx>
TEST_MACROS();
#include <cstdio.hxx>
TEST_MACROS();
#include <cstdlib.hxx>
TEST_MACROS();
#include <cstring.hxx>
TEST_MACROS();
#include <ctgmath.hxx>
TEST_MACROS();
#include <ctime.hxx>
TEST_MACROS();
#include <ctype.h>
TEST_MACROS();
#include <cwchar.hxx>
TEST_MACROS();
#include <cwctype.hxx>
TEST_MACROS();
#include <deque.hxx>
TEST_MACROS();
#include <errno.h>
TEST_MACROS();
#include <exception.hxx>
TEST_MACROS();
#include <filesystem.hxx>
TEST_MACROS();
#include <float.h>
TEST_MACROS();
#include <forward_list.hxx>
TEST_MACROS();
#include <fstream.hxx>
TEST_MACROS();
#include <functional.hxx>
TEST_MACROS();
#ifndef _LIBCPP_HAS_NO_THREADS
#include <future.hxx>
TEST_MACROS();
#endif
#include <initializer_list.hxx>
TEST_MACROS();
#include <inttypes.h>
TEST_MACROS();
#include <iomanip.hxx>
TEST_MACROS();
#include <ios.hxx>
TEST_MACROS();
#include <iosfwd.hxx>
TEST_MACROS();
#include <iostream.hxx>
TEST_MACROS();
#include <istream.hxx>
TEST_MACROS();
#include <iterator.hxx>
TEST_MACROS();
#include <limits.hxx>
TEST_MACROS();
#include <limits.h>
TEST_MACROS();
#include <list.hxx>
TEST_MACROS();
#include <locale.hxx>
TEST_MACROS();
#include <locale.h>
TEST_MACROS();
#include <map.hxx>
TEST_MACROS();
#include <math.h>
TEST_MACROS();
#include <memory.hxx>
TEST_MACROS();
#ifndef _LIBCPP_HAS_NO_THREADS
#include <mutex.hxx>
TEST_MACROS();
#endif
#include <new.hxx>
TEST_MACROS();
#include <numeric.hxx>
TEST_MACROS();
#include <optional.hxx>
TEST_MACROS();
#include <ostream.hxx>
TEST_MACROS();
#include <queue.hxx>
TEST_MACROS();
#include <random.hxx>
TEST_MACROS();
#include <ratio.hxx>
TEST_MACROS();
#include <regex.hxx>
TEST_MACROS();
#include <scoped_allocator.hxx>
TEST_MACROS();
#include <set.hxx>
TEST_MACROS();
#include <setjmp.h>
TEST_MACROS();
#ifndef _LIBCPP_HAS_NO_THREADS
#include <shared_mutex.hxx>
TEST_MACROS();
#endif
#include <sstream.hxx>
TEST_MACROS();
#include <stack.hxx>
TEST_MACROS();
#include <stdbool.h>
TEST_MACROS();
#include <stddef.h>
TEST_MACROS();
#include <stdexcept.hxx>
TEST_MACROS();
#include <stdint.h>
TEST_MACROS();
#include <stdio.h>
TEST_MACROS();
#include <stdlib.h>
TEST_MACROS();
#include <streambuf.hxx>
TEST_MACROS();
#include <string.hxx>
TEST_MACROS();
#include <string.h>
TEST_MACROS();
#include <string_view.hxx>
TEST_MACROS();
#include <strstream.hxx>
TEST_MACROS();
#include <system_error.hxx>
TEST_MACROS();
#include <tgmath.h>
TEST_MACROS();
#ifndef _LIBCPP_HAS_NO_THREADS
#include <thread.hxx>
TEST_MACROS();
#endif
#include <tuple.hxx>
TEST_MACROS();
#include <typeindex.hxx>
TEST_MACROS();
#include <typeinfo.hxx>
TEST_MACROS();
#include <type_traits.hxx>
TEST_MACROS();
#include <unordered_map.hxx>
TEST_MACROS();
#include <unordered_set.hxx>
TEST_MACROS();
#include <utility.hxx>
TEST_MACROS();
#include <valarray.hxx>
TEST_MACROS();
#include <variant.hxx>
TEST_MACROS();
#include <vector.hxx>
TEST_MACROS();
#include <wchar.h>
TEST_MACROS();
#include <wctype.h>
TEST_MACROS();

// experimental headers
#if __cplusplus >= 201103L
#include <experimental/algorithm.hxx>
TEST_MACROS();
#include <experimental/deque.hxx>
TEST_MACROS();
#include <experimental/filesystem.hxx>
TEST_MACROS();
#include <experimental/forward_list.hxx>
TEST_MACROS();
#include <experimental/functional.hxx>
TEST_MACROS();
#include <experimental/iterator.hxx>
TEST_MACROS();
#include <experimental/list.hxx>
TEST_MACROS();
#include <experimental/map.hxx>
TEST_MACROS();
#include <experimental/memory_resource.hxx>
TEST_MACROS();
#include <experimental/propagate_const.hxx>
TEST_MACROS();
#include <experimental/regex.hxx>
TEST_MACROS();
#include <experimental/set.hxx>
TEST_MACROS();
#include <experimental/string.hxx>
TEST_MACROS();
#include <experimental/type_traits.hxx>
TEST_MACROS();
#include <experimental/unordered_map.hxx>
TEST_MACROS();
#include <experimental/unordered_set.hxx>
TEST_MACROS();
#include <experimental/utility.hxx>
TEST_MACROS();
#include <experimental/vector.hxx>
TEST_MACROS();
#endif // __cplusplus >= 201103L

// extended headers
#include <ext/hash_map.hxx>
TEST_MACROS();
#include <ext/hash_set.hxx>
TEST_MACROS();
