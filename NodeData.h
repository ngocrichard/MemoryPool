#pragma once
#ifndef NODE_DATA_H__
#define NODE_DATA_H__
#include "Node.h"

namespace mempool
{
	struct Data
	{
		int size;
		char *offset;
		Data(); // Default constructor
		Data(int newSize, char *newOffset); // Constructor
	};
	typedef data_structure::Node<Data> NodeData;
}

#endif // !NODE_DATA_H__

