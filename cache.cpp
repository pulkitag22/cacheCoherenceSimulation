#include "typedefs.h"

class Cache
{
protected:
    ulong cacheSize, blockSize, associativity, numOfSets, index, numOfBitsSets, numOfBitsBlock, tagMask;
    ulong reads, readMisses, writes, writeMisses, writeBacks;
    ulong busRead, intervention, invalidate, cacheToCache, flushes, memoryTransactions;
    int procs;

    cacheLine **cache;
    ulong calcTag(ulong address)
    {
        return address >> numOfBitsBlock;
    }

    ulong calcIndex(ulong address)
    {
        return (address >> numOfBitsBlock) & tagMask;
    }

    ulong calcAddressForTag(ulong tag)
    {
        return tag << numOfBitsBlock;
    }

public:
    ulong currentCycle;

    // constructor and the destructor.

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

    void updateWriteBack()
    {
        writeBacks++;
    }

    // 3 functions after the writeBack in the ref code.
    // cacheLine 4 functions in the ref. code.
}