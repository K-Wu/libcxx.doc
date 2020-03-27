// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Ensure that none of the standard C++ headers implicitly include cassert or
// assert.h (because assert() is implemented as a macro).

// RUN: %compile -fsyntax-only

// Prevent <ext/hash_map> from generating deprecated warnings for this test.
#if defined(__DEPRECATED)
#undef __DEPRECATED
#endif

// Top level headers
#include <algorithm.hxx>
#include <any.hxx>
#include <array.hxx>
#ifndef _LIBCPP_HAS_NO_THREADS
#include <atomic.hxx>
#endif
#include <bit.hxx>
#include <bitset.hxx>
#include <ccomplex.hxx>
#include <cctype.hxx>
#include <cerrno.hxx>
#include <cfenv.hxx>
#include <cfloat.hxx>
#include <charconv.hxx>
#include <chrono.hxx>
#include <cinttypes.hxx>
#include <ciso646.hxx>
#include <climits.hxx>
#include <clocale.hxx>
#include <cmath.hxx>
#include <codecvt.hxx>
#include <compare.hxx>
#include <complex.hxx>
#include <complex.h>
#include <condition_variable.hxx>
#include <csetjmp.hxx>
#include <csignal.hxx>
#include <cstdarg.hxx>
#include <cstdbool.hxx>
#include <cstddef.hxx>
#include <cstdint.hxx>
#include <cstdio.hxx>
#include <cstdlib.hxx>
#include <cstring.hxx>
#include <ctgmath.hxx>
#include <ctime.hxx>
#include <ctype.h>
#include <cwchar.hxx>
#include <cwctype.hxx>
#include <deque.hxx>
#include <errno.h>
#include <exception.hxx>
#include <execution.hxx>
#include <fenv.h>
#include <filesystem.hxx>
#include <float.h>
#include <forward_list.hxx>
#include <fstream.hxx>
#include <functional.hxx>
#ifndef _LIBCPP_HAS_NO_THREADS
#include <future.hxx>
#endif
#include <initializer_list.hxx>
#include <inttypes.h>
#include <iomanip.hxx>
#include <ios.hxx>
#include <iosfwd.hxx>
#include <iostream.hxx>
#include <istream.hxx>
#include <iterator.hxx>
#include <limits.hxx>
#include <limits.h>
#include <list.hxx>
#include <locale.hxx>
#include <locale.h>
#include <map.hxx>
#include <math.h>
#include <memory.hxx>
#ifndef _LIBCPP_HAS_NO_THREADS
#include <mutex.hxx>
#endif
#include <new.hxx>
#include <numeric.hxx>
#include <optional.hxx>
#include <ostream.hxx>
#include <queue.hxx>
#include <random.hxx>
#include <ratio.hxx>
#include <regex.hxx>
#include <scoped_allocator.hxx>
#include <set.hxx>
#include <setjmp.h>
#ifndef _LIBCPP_HAS_NO_THREADS
#include <shared_mutex.hxx>
#endif
#include <span.hxx>
#include <sstream.hxx>
#include <stack.hxx>
#include <stdbool.h>
#include <stddef.h>
#include <stdexcept.hxx>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <streambuf.hxx>
#include <string.hxx>
#include <string.h>
#include <string_view.hxx>
#include <strstream.hxx>
#include <system_error.hxx>
#include <tgmath.h>
#ifndef _LIBCPP_HAS_NO_THREADS
#include <thread.hxx>
#endif
#include <tuple.hxx>
#include <typeindex.hxx>
#include <typeinfo.hxx>
#include <type_traits.hxx>
#include <unordered_map.hxx>
#include <unordered_set.hxx>
#include <utility.hxx>
#include <valarray.hxx>
#include <variant.hxx>
#include <vector.hxx>
#include <version.hxx>
#include <wchar.h>
#include <wctype.h>

// experimental headers
#if __cplusplus >= 201103L
#include <experimental/algorithm.hxx>
#if defined(__cpp_coroutines)
#include <experimental/coroutine.hxx>
#endif
#include <experimental/deque.hxx>
#include <experimental/filesystem.hxx>
#include <experimental/forward_list.hxx>
#include <experimental/functional.hxx>
#include <experimental/iterator.hxx>
#include <experimental/list.hxx>
#include <experimental/map.hxx>
#include <experimental/memory_resource.hxx>
#include <experimental/propagate_const.hxx>
#include <experimental/regex.hxx>
#include <experimental/simd.hxx>
#include <experimental/set.hxx>
#include <experimental/string.hxx>
#include <experimental/type_traits.hxx>
#include <experimental/unordered_map.hxx>
#include <experimental/unordered_set.hxx>
#include <experimental/utility.hxx>
#include <experimental/vector.hxx>
#endif // __cplusplus >= 201103L

// extended headers
#include <ext/hash_map.hxx>
#include <ext/hash_set.hxx>

#ifdef assert
#error "Do not include cassert or assert.h in standard header files"
#endif
