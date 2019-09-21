#include "MemoryPool.h"


namespace mempool
{
#pragma region
	// Default constructor
	MemoryPool::MemoryPool() : FrameMemoryPool() {}
	// Constructor by size
	MemoryPool::MemoryPool(int sizeOfPool) : FrameMemoryPool(sizeOfPool) {}
	// Destructor
	MemoryPool::~MemoryPool() {}
#pragma endregion Constructors and destructor.

#pragma region
	// Check if overflow
	bool MemoryPool::isOverFlow(char * newData, int sizeOfNode)
	{
		if (newData + sizeOfNode - 1 <= addressOfMemoryPool + size - 1)
			return false;
		else
			return true;
	}
	
	// Allocate memory if list is empty
	int MemoryPool::allocateMemIfEmpty(int sizeOfNode)
	{
		// Create default return value
		int newID = -1;
		// Try to construct new node to store offset
		if (!isOverFlow(addressOfMemoryPool, sizeOfNode))
		{
			addTail(NodeData(++lastID, { sizeOfNode, addressOfMemoryPool }));
			newID = lastID;
		}
		return newID;
	}

	// Allocate memory at tail
	int MemoryPool::allocateMemAtTail(int sizeOfNode)
	{
		// Create default return value
		int newID = -1;
		char *newNodePosition = tail->data.offset + tail->data.size;
		if (!isOverFlow(newNodePosition, sizeOfNode))
		{
			// Construct new node to store offset	
			addTail(NodeData(++lastID, { sizeOfNode, newNodePosition }));
			newID = lastID;
		}
		return newID;
	}

	// Allocate memory at middle
	int MemoryPool::allocateMemAtMiddle(int sizeOfNode)
	{
		// Create default return value
		int newID = -1;
		// Check if can allocate at head
		if (addressOfMemoryPool + sizeOfNode - 1 < head->data.offset)
		{
			addHead(NodeData(++lastID, { sizeOfNode, addressOfMemoryPool }));
			newID = lastID;
		}
		else
		{
			// If cannot, allocate at head, find position to add
			for (NodeData *ptr = head; ptr->next != nullptr; ptr = ptr->next)
			{
				char *newNodePosition = ptr->data.offset + ptr->data.size;
				if (newNodePosition + sizeOfNode - 1 < ptr->next->data.offset)
				{
					addMiddle(NodeData(++lastID, { sizeOfNode,  newNodePosition }), ptr);
					newID = lastID;
					break;
				}
			}
		}
		return newID;
	}

	// Allocate memory
	int MemoryPool::allocateMem(int sizeOfNode)
	{
		// Create default return value for function
		int newID = -1;
		// Check if list is empty
		if (isEmptyList())
		{
			// Allocate first data memory
			newID = allocateMemIfEmpty(sizeOfNode);
		}
		// If list is not empty
		else
		{
			// Try to add at tail
			newID = allocateMemAtTail(sizeOfNode);
			if (newID == -1)
			{
				// Try to add at somewhere in the middle
				newID = allocateMemAtMiddle(sizeOfNode);
				if (newID == -1)
				{
					// Sort data to defrag memory
					sort();
					// Try to add again, tail then middle
					newID = allocateMemAtTail(sizeOfNode);
					if (newID == -1)
					{
						newID = allocateMemAtMiddle(sizeOfNode);
					}	
				}
			}
		}
		return newID;
	}
#pragma endregion Allocate memory.

#pragma region
	// Sort the linked list when cannot allocate new memory
	void MemoryPool::sort()
	{
		for (NodeData *ptr = head; ptr != nullptr; ptr = ptr->next)
		{
			if (ptr == head)
			{
				// Move block of memory of head to address of memory pool
				memmove(addressOfMemoryPool, ptr->data.offset, ptr->data.size);
				ptr->data.offset = addressOfMemoryPool;
			}
			else
			{
				// Move block of memory
				char *destination = (ptr->prev)->data.offset + (ptr->prev)->data.size;
				memmove(destination, ptr->data.offset, ptr->data.size);
				ptr->data.offset = destination;
			}
		}
	}
#pragma endregion Sort memory.

#pragma region
	// Free memory by ID
	bool MemoryPool::freeMem(int IDOfNode)
	{
		return deleteByID(IDOfNode);
	}
#pragma endregion Free memory.

#pragma region
	// Print memory
	void MemoryPool::printMemory()
	{
		std::cout << "\n===========================MEMORY POOL TEST===========================";
		std::cout << "\nAddress:\n";
		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << i % 10;
		}
		std::cout << "\nMemory:\n";
		char j = 'x'; // What to print of single Node
		// Check every byte of memory pool
		for (char *ptr = addressOfMemoryPool; ptr < (char *)addressOfMemoryPool + size;)
		{
			NodeData *temp = head;
			// Check the list
			bool isNotAllocated = false;
			while (temp != nullptr)
			{
				if (temp->data.offset == ptr)
				{
					isNotAllocated = true;
					// Print zone of temp
					for (int i = 0; i < temp->data.size; i++)
					{
						std::cout << j;
					}
					ptr += temp->data.size; // Jump to new node
					// Change what to print of Node
					if (j == 'x')
						j = 'O';
					else
						j = 'x';
				}
				temp = temp->next;
			}
			if (!isNotAllocated)
			{
				std::cout << "-";
				ptr++;
			}
		}
		std::cout << "\n======================================================================\n\n";
	}
#pragma endregion Print memory.
}
