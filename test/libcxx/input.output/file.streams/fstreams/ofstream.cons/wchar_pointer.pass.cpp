//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_ofstream

// explicit basic_ofstream(const wchar_t* s, ios_base::openmode mode = ios_base::out);

#include <fstream.hxx>
#include <cassert.hxx>
#include "test_macros.h"
#include "platform_support.h"

int main(int, char**)
{
#ifdef _LIBCPP_HAS_OPEN_WITH_WCHAR
    std::wstring temp = get_wide_temp_file_name();
    {
        std::ofstream fs(temp.c_str());
        fs << 3.25;
    }
    {
        std::ifstream fs(temp.c_str());
        double x = 0;
        fs >> x;
        assert(x == 3.25);
    }
    {
        std::ifstream fs(temp.c_str(), std::ios_base::out);
        double x = 0;
        fs >> x;
        assert(x == 3.25);
    }
    _wremove(temp.c_str());
    {
        std::wofstream fs(temp.c_str());
        fs << 3.25;
    }
    {
        std::wifstream fs(temp.c_str());
        double x = 0;
        fs >> x;
        assert(x == 3.25);
    }
    {
        std::wifstream fs(temp.c_str(), std::ios_base::out);
        double x = 0;
        fs >> x;
        assert(x == 3.25);
    }
    _wremove(temp.c_str());
#endif

  return 0;
}
