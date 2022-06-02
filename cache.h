#include "cacheLine.h"
#include <cmath>

class Cache
{
protected:
    ulong cacheSize, blockSize, associativity, numOfSets, index, numOfBitsSets, numOfBitsBlock, tagMask;
    ulong reads, readMisses, writes, writeMisses, writeBacks;
    ulong busRead, intervention, invalidate, cacheToCache, flushes, memoryTransactions;
    int procs;

    CacheLine **cache;
    ulong calcTag(ulong address);
    ulong calcIndex(ulong address);
    ulong calcAddressForTag(ulong tag);

public:
    ulong currentCycle;
    Cache(int cacheSize, int blockSize, int associativity, int procs);
    ~Cache()
    {
        delete cache;
    };

    ulong getReadMisses()
    {
        return readMisses;
    }

    ulong getWriteMisses()
    {
        return writeMisses;
    }

    ulong getReads()
    {
        return reads;
    }

    ulong getWrites()
    {
        return writes;
    }

    ulong getWriteBacks()
    {
        return writeBacks;
    }

    ulong getInvalid()
    {
        return invalidate;
    }

    ulong getIntervention()
    {
        return intervention;
    }

    ulong getFlushes()
    {
        return flushes;
    }

    ulong getBusReads()
    {
        return busRead;
    }

    ulong getCacheToCache()
    {
        return cacheToCache;
    }

    void updateWriteBack();

    // 3 functions after the writeBack in the ref code.
    // cacheLine 4 functions in the ref. code.
};
