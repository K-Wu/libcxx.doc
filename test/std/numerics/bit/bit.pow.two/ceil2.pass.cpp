//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++98, c++03, c++11, c++14, c++17 

// template <class T>
//   constexpr T ceil2(T x) noexcept;

// Returns: The minimal value y such that ispow2(y) is true and y >= x; 
//    if y is not representable as a value of type T, the result is an unspecified value.
// Remarks: This function shall not participate in overload resolution unless 
//  T is an unsigned integer type

#include <bit.hxx>
#include <cstdint.hxx>
#include <type_traits.hxx>
#include <cassert.hxx>

#include "test_macros.h"

class A{};
enum       E1 : unsigned char { rEd };
enum class E2 : unsigned char { red };

template <typename T>
constexpr bool constexpr_test()
{
    return std::ceil2(T(0)) == T(1)
       &&  std::ceil2(T(1)) == T(1)
       &&  std::ceil2(T(2)) == T(2)
       &&  std::ceil2(T(3)) == T(4)
       &&  std::ceil2(T(4)) == T(4)
       &&  std::ceil2(T(5)) == T(8)
       &&  std::ceil2(T(6)) == T(8)
       &&  std::ceil2(T(7)) == T(8)
       &&  std::ceil2(T(8)) == T(8)
       &&  std::ceil2(T(9)) == T(16)
       ;
}


template <typename T>
void runtime_test()
{
    ASSERT_SAME_TYPE(T, decltype(std::ceil2(T(0))));
    LIBCPP_ASSERT_NOEXCEPT(      std::ceil2(T(0)));
    
    assert( std::ceil2(T(60)) == T( 64));
    assert( std::ceil2(T(61)) == T( 64));
    assert( std::ceil2(T(62)) == T( 64));
    assert( std::ceil2(T(63)) == T( 64));
    assert( std::ceil2(T(64)) == T( 64));
    assert( std::ceil2(T(65)) == T(128));
    assert( std::ceil2(T(66)) == T(128));
    assert( std::ceil2(T(67)) == T(128));
    assert( std::ceil2(T(68)) == T(128));
    assert( std::ceil2(T(69)) == T(128));
}

int main()
{
    
    {
    auto lambda = [](auto x) -> decltype(std::ceil2(x)) {};
    using L = decltype(lambda);
    
    static_assert( std::is_invocable_v<L, unsigned char>, "");
    static_assert( std::is_invocable_v<L, unsigned int>, "");
    static_assert( std::is_invocable_v<L, unsigned long>, "");
    static_assert( std::is_invocable_v<L, unsigned long long>, "");

    static_assert( std::is_invocable_v<L, uint8_t>, "");
    static_assert( std::is_invocable_v<L, uint16_t>, "");
    static_assert( std::is_invocable_v<L, uint32_t>, "");
    static_assert( std::is_invocable_v<L, uint64_t>, "");
    static_assert( std::is_invocable_v<L, size_t>, "");

    static_assert( std::is_invocable_v<L, uintmax_t>, "");
    static_assert( std::is_invocable_v<L, uintptr_t>, "");


    static_assert(!std::is_invocable_v<L, int>, "");
    static_assert(!std::is_invocable_v<L, signed int>, "");
    static_assert(!std::is_invocable_v<L, long>, "");
    static_assert(!std::is_invocable_v<L, long long>, "");

    static_assert(!std::is_invocable_v<L, int8_t>, "");
    static_assert(!std::is_invocable_v<L, int16_t>, "");
    static_assert(!std::is_invocable_v<L, int32_t>, "");
    static_assert(!std::is_invocable_v<L, int64_t>, "");
    static_assert(!std::is_invocable_v<L, ptrdiff_t>, "");

    static_assert(!std::is_invocable_v<L, bool>, "");
    static_assert(!std::is_invocable_v<L, signed char>, "");
    static_assert(!std::is_invocable_v<L, char16_t>, "");
    static_assert(!std::is_invocable_v<L, char32_t>, "");

#ifndef _LIBCPP_HAS_NO_INT128
    static_assert( std::is_invocable_v<L, __uint128_t>, "");
    static_assert(!std::is_invocable_v<L, __int128_t>, "");
#endif
 
    static_assert(!std::is_invocable_v<L, A>, "");
    static_assert(!std::is_invocable_v<L, E1>, "");
    static_assert(!std::is_invocable_v<L, E2>, "");
    }

    static_assert(constexpr_test<unsigned char>(),      "");
    static_assert(constexpr_test<unsigned short>(),     "");
    static_assert(constexpr_test<unsigned>(),           "");
    static_assert(constexpr_test<unsigned long>(),      "");
    static_assert(constexpr_test<unsigned long long>(), "");

    static_assert(constexpr_test<uint8_t>(),   "");
    static_assert(constexpr_test<uint16_t>(),  "");
    static_assert(constexpr_test<uint32_t>(),  "");
    static_assert(constexpr_test<uint64_t>(),  "");
    static_assert(constexpr_test<size_t>(),    "");
    static_assert(constexpr_test<uintmax_t>(), "");
    static_assert(constexpr_test<uintptr_t>(), "");

#ifndef _LIBCPP_HAS_NO_INT128
    static_assert(constexpr_test<__uint128_t>(),        "");
#endif

    runtime_test<unsigned char>();
    runtime_test<unsigned>();
    runtime_test<unsigned short>();
    runtime_test<unsigned long>();
    runtime_test<unsigned long long>();

    runtime_test<uint8_t>();
    runtime_test<uint16_t>();
    runtime_test<uint32_t>();
    runtime_test<uint64_t>();
    runtime_test<size_t>();
    runtime_test<uintmax_t>();
    runtime_test<uintptr_t>();

#ifndef _LIBCPP_HAS_NO_INT128
    runtime_test<__uint128_t>();
#endif
}
