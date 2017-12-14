//--------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #1: Priority Queues
//--------------------------------------------------------
//
/**  PriorityQueue.cc

	 C++ Code file that contains the implementation of the PriorityQueue.	 
**/

#include "PriorityQueue.h"

template<class Object>
void PriorityQueue<Object>::InsertElement(Object data, int priority)
{
	// create a new node. . .
	Node<Object> *newNode = new Node<Object>(data, priority);

	// if memory is exhausted, simply return from this method.
	if (newNode == NULL) return;

	// otherwise, assign the new node to its proper location:
	if (front == NULL)		// Queue is empty
		front = newNode;
	else {					// Queue is NOT empty
		Node<Object> *currentNode = front;			

		// This is a special case, that is when we have only one node,
		// and the new node has a higher priority than the current:

		if (priority < currentNode->priority) {
			newNode->next = front;
			front = newNode;
			size++;
			return;
		}

		// Most of the cases hold here:

		while (currentNode->next != NULL) {
			int prevPriority = currentNode->priority;
			int nextPriority = currentNode->next->priority;
			
			// a node is in its right position if it lies between two proper priorities...

			if (priority >= prevPriority && priority < nextPriority) {
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				size++;
				return;
			}

			currentNode = currentNode->next;
		}				
		
		// We reached the end of the queue, but we didn't find a proper position, so
		// we add the node to the end of the queue considering the priorities:

		if (currentNode->next == NULL)
			if (priority >= currentNode->priority) {
				currentNode->next = newNode;
				newNode->next = NULL;
			}
			else {
				newNode->next = currentNode;
				currentNode->next = NULL;
			}					
	}
	size++;
}

template<class Object>
Object PriorityQueue<Object>::RemoveTopElement()
{
	// Return the default constructor of an object if the queue is empty on a remove:
	// for example, the default constructor for an integer is int() = 0.
	if (IsEmpty()) return Object();

	// Preserve the data to be returned before deletion. . .
	Object retData = front->entry;

	// Delete top node. . .
	Node<Object> *oldFront = front;
	front = front->next;
	delete oldFront;
	oldFront = NULL;

	size--;

	return (retData);
}

template<class Object>
inline int PriorityQueue<Object>::Size() const 
{
	return (size);
}

template<class Object>
inline bool PriorityQueue<Object>::IsEmpty() const
{
	return (front == NULL);
}

template<class Object>
void PriorityQueue<Object>::Clear()
{	
	while (!IsEmpty())
		RemoveTopElement();	
}

template<class Object>
PriorityQueue<Object>::~PriorityQueue()
{
	Clear();
}
