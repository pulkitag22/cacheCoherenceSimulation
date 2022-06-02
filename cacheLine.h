#include "typedefs.h"

class CacheLine
{
protected:
    ulong tag;
    ulong flags;
    ulong sequence;

public:
    CacheLine()
    {
        tag = 0;
        flags = 0;
    }

    void setTag(ulong inTag)
    {
        tag = inTag;
    }

    void setFlags(ulong inFlags)
    {
        flags = inFlags;
    }

    void setSequence(ulong inSequence)
    {
        sequence = inSequence;
    }

    ulong getTag()
    {
        return tag;
    }

    ulong getFlags()
    {
        return flags;
    }

    ulong getSequence()
    {
        return sequence;
    }

    void invalidate();
    bool isValid();
    
};