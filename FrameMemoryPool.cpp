#include "FrameMemoryPool.h"

namespace mempool
{
	// Default constructor
	FrameMemoryPool::FrameMemoryPool() : LinkedList()
	{
		addressOfMemoryPool = nullptr;
		lastID = 0;
		sizeInMB = 0;
		size = 0;
	}

	// Constructor by size
	FrameMemoryPool::FrameMemoryPool(int sizeOfPoolInMB) : FrameMemoryPool()
	{
		sizeInMB = sizeOfPoolInMB;
		size = sizeInMB; // Just for test
		//size = sizeInMB * 1024 * 1024; // Actual code
		addressOfMemoryPool = (char *)malloc(size);
	}

	// Destructor
	FrameMemoryPool::~FrameMemoryPool()
	{
		free(addressOfMemoryPool); addressOfMemoryPool = nullptr;
	}

	// Get size in MB
	unsigned int FrameMemoryPool::getSizeInMB()
	{
		return sizeInMB;
	}
}