#pragma once
#ifndef NODE_H__
#define NODE_H__

// Declare prototype
namespace data_structure
{
	template<class __Ty>
	struct Node
	{
		unsigned int ID;
		Node<__Ty> *next, *prev; // Pointer to previous node and next node
		__Ty data;
		Node(); // Default constructor
		Node(unsigned int newID, __Ty &&); // Constructor
	};
}

// Declare definition
namespace data_structure
{
	// Default constructor
	template<class __Ty>
	Node<__Ty>::Node()
	{
		ID = 0;
		data = __Ty();
		next = nullptr;
		prev = nullptr;
	}
	// Construct node by size and ID
	template<class __Ty>
	Node<__Ty>::Node(unsigned int newID, __Ty &&node) : Node<__Ty>()
	{
		ID = newID;
		data = __Ty(node);
	}
}

#endif // !NODE_H__