#include "List.h"

namespace mempool
{
	// Constructor
	LinkedList::LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	// Destructor
	LinkedList::~LinkedList() {};
	
	// Check if list is empty
	bool LinkedList::isEmptyList()
	{
		if (tail == nullptr)
			return true;
		else
			return false;
	}

	// Add node at head
	void LinkedList::addHead(NodeData &&node)
	{
		NodeData *temp = new NodeData(node);
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	// Add node at tail
	void LinkedList::addTail(NodeData &&node)
	{
		// If list is empty
		if (tail == nullptr)
		{
			tail = new NodeData(node);
			head = tail;
		}
		// If list is not empty
		else
		{
			NodeData *temp = new NodeData(node);
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	// Add node after position
	void LinkedList::addMiddle(NodeData &&node, NodeData *position)
	{
		NodeData *temp = new NodeData(node);
		temp->next = position->next;
		temp->prev = position;
		(position->next)->prev = temp;
		position->next = temp;
	}

	// Delete node by ID
	bool LinkedList::deleteByID(int IDToDelete)
	{
		// Create default return value
		bool isSuccess = false;
		// Check if list is empty
		if (isEmptyList())
		{
			isSuccess = false;
		}
		else
		{
			// Check if node to delete is head
			if (head->ID == IDToDelete)
			{
				// If list has only head, the list will be empty
				if (head->next == nullptr)
				{
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				// If list has more than one node
				else
				{
					NodeData *temp = head->next;
					delete head;
					head = temp;
					head->prev = nullptr;
				}
				isSuccess = true;
			}
			// If node to delete is not head
			else
			{
				// Check if node to delete is tail
				if (tail->ID == IDToDelete)
				{
					NodeData *temp = tail->prev;
					delete tail;
					tail = temp;
					tail->next = nullptr;
					isSuccess = true;
				}
				// The node to delet is in the middle
				else
				{
					for (NodeData *ptr = head; ptr->next; ptr = ptr->next)
					{
						// If the node to delete is founded
						if (ptr->next->ID == IDToDelete)
						{
							// Delte the node
							NodeData *temp = ptr->next;
							ptr->next = temp->next;
							(temp->next)->prev = ptr;
							delete temp; temp = nullptr;
							isSuccess = true;
						}
					}
				}
			}
		}
		return isSuccess;
	}
}