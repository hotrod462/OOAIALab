#include "Faculty.h"

Faculty::Faculty(std::string tempname, bool permStat)
{
    name = tempname;
    isPerm = permStat;
}

Faculty::Faculty(){}