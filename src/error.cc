#include <iostream>
#include "error.h"

void error(::std::string msg)
{
    ::std::cout << "[Error] " << msg << ::std::endl;
}
