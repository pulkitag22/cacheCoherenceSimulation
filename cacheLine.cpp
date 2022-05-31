#include "typedefs.h"

class CacheLine
{
protected:
    ulong tag;
    ulong flags;
    ulong sequence;

public:
    void cacheLine()
    {
        ulong tag = 0;
        ulong flags = 0;
    }

    void setTag(ulong inTag)
    {
        tag = inTag;
    }

    ulong getTag()
    {
        return tag;
    }

    void setFlags(ulong inFlags)
    {
        flags = inFlags;
    }

    ulong getFlags()
    {
        return flags;
    }

    void setSequence(ulong inSequence)
    {
        sequence = inSequence;
    }

    ulong getsequence()
    {
        return sequence;
    }

    void invalidate()
    {
        tag = 0;
        flags = INVALID;
    }

    bool isValid()
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
};