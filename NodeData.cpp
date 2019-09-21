#include "NodeData.h"

namespace mempool
{
	// Constructor
	Data::Data()
	{
		size = 0;
		offset = nullptr;
	}
	// Constructor
	Data::Data(int newSize, char * newOffset)
	{
		size = newSize;
		offset = newOffset;
	}
}


