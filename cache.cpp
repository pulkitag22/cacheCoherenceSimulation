#include "cache.h"

Cache::Cache(int cacheSize, int blockSize, int associativity, int procs)
{
    this->cacheSize = (ulong)cacheSize;
    this->blockSize = (ulong)blockSize;
    this->associativity = (ulong)associativity;
    this->procs = procs;
    this->numOfSets = (ulong)(cacheSize / (blockSize * associativity));
    this->numOfBitsSets = (ulong)log2(numOfSets);
    this->numOfBitsBlock = (ulong)log2(blockSize);
    this->tagMask = (ulong)((1 << numOfBitsSets) - 1); // 1111...1 (numOfBitsSets 1's) (look into this, Co-Pilot generated...) Thank you Co-Pilot <3
    this->reads = (ulong)0;
    this->readMisses = (ulong)0;
    this->writes = (ulong)0;
    this->writeMisses = (ulong)0;
    this->writeBacks = (ulong)0;
    this->busRead = (ulong)0;
    this->intervention = (ulong)0;
    this->invalidate = (ulong)0;
    this->cacheToCache = (ulong)0;
    this->flushes = (ulong)0;
    this->memoryTransactions = (ulong)0;
    this->currentCycle = (ulong)0;

    this->cache = new CacheLine *[numOfSets];
    for (int i = 0; i < numOfSets; i++)
    {
        this->cache[i] = new CacheLine[associativity];
        for (int j = 0; j < associativity; j++)
        {
            this->cache[i][j].invalidate();
        }
    }
}



ulong Cache::calcTag(ulong address)
{
    return address >> numOfBitsBlock;
}

ulong Cache::calcIndex(ulong address)
{
    return (address >> numOfBitsBlock) & tagMask;
}

ulong Cache::calcAddressForTag(ulong tag)
{
    return tag << numOfBitsBlock;
}

void Cache::updateWriteBack()
{
    writeBacks++;
}
