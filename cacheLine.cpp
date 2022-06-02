#include "cacheLine.h"

void CacheLine::invalidate()
{
    tag = 0;
    flags = INVALID;
}

bool CacheLine::isValid()
{
    if (flags == INVALID)
    {
        return false;
    }
    else
    {
        return true;
    }
}