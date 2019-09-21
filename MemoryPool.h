#pragma once
#ifndef MEMORY_POOL_H__
#define MEMORY_POOL_H__

#include "FrameMemoryPool.h"

namespace mempool
{
	class MemoryPool :	public FrameMemoryPool
	{
	public:
		MemoryPool(); // Default constructor
		MemoryPool(int sizeOfPool); // Constructor by size
		virtual ~MemoryPool(); // Destructor
		int allocateMem(int sizeOfNode); // Allocate memory then return ID
		bool freeMem(int IDOfNode); // Free memory by ID
		void printMemory(); // Print memory for debug
	protected:
		bool isOverFlow(char *newData, int sizeOfNode); // Check if the position is valid
		int allocateMemIfEmpty(int sizeOfNode); // Insert node if empty
		int allocateMemAtTail(int sizeOfNode); // Insert node at tail
		int allocateMemAtMiddle(int sizeOfNode); // Insert node at middle
		void sort(); // Sort the linked list when cannot allocate memory
	};
}

#endif // !MEMORY_POOL_H__

