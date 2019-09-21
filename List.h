#pragma once
#ifndef LIST_H__
#define LIST_H__
#include "NodeData.h"

namespace mempool
{
	class LinkedList
	{
	public:
		LinkedList(); // Constructor
		virtual ~LinkedList(); // Destructor
		bool isEmptyList(); // Check if list is empty
		void addHead(NodeData &&); // Add new node at head of list
		void addTail(NodeData &&); // Add new node at tail of list
		void addMiddle(NodeData &&, NodeData *position); // Add new node at middle of list
		bool deleteByID(int IDToDelete); // Delete node by ID
	protected:
		NodeData *head, *tail;
	};
}

#endif // !LIST_H__

