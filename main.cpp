
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "TimeGuard.hpp"
#include "show.h"

#include "Sorting.hpp"
#include "ListNode.h"

#include <fmt/ranges.h>


//==============================================================================//
int main()
{
    TimeGuard timer("Main.cpp");

    std::vector v{1,2,3,4};
    fmt::print("{}", v);
     
}

