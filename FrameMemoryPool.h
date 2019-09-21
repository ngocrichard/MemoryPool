#pragma once
#ifndef FRAME_MEMORY_POOL_H__
#define FRAME_MEMORY_POOL_H__

#include "List.h"
#include <iostream>

namespace mempool
{
	class FrameMemoryPool : public LinkedList
	{
	public:
		unsigned int getSizeInMB(); // Get size of memory block in MB
		FrameMemoryPool(); // Default constructor
		FrameMemoryPool(int sizeOfPoolInMB); // Constructor by size
		virtual ~FrameMemoryPool(); // Destructor
	protected:
		char *addressOfMemoryPool; // Pointer to memory bool
		unsigned int sizeInMB; // Store size of memory block in MB
		unsigned int size; // Store size of memory block in byte
		unsigned int lastID; // Store the current last ID
	};
}

#endif // !FRAME_MEMORY_POOL_H__
