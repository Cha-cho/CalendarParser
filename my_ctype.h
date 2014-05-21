//
//  my_ctype.h
//  CalendarParser
//
//  Created by Matthew Weser on 5/21/14.
//  Copyright (c) 2014 mweser. All rights reserved.
//

#ifndef __CalendarParser__my_ctype__
#define __CalendarParser__my_ctype__

#include <locale>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

class my_ctype : public
std::ctype<char>
{
    mask my_table[table_size];
public:
    my_ctype(size_t refs = 0)
    : std::ctype<char>(&my_table[0], false, refs)
    {
    std::copy_n(classic_table(), table_size, my_table);
    my_table[':'] = (mask)space;
    my_table['\n'] = (mask)space;
    }
};

#endif /* defined(__CalendarParser__my_ctype__) */
