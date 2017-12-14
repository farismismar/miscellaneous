//--------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #1: Priority Queues
//--------------------------------------------------------
//
/**  PriorityQueue.h

	 A Header file that contains the definitions of the PriorityQueue
	 Node<Object>:				Structure (or Class) that holds a "process".
	 PriorityQueue<Object>:		Composed of several Nodes linked together.

**/
#ifndef PRIORITY_H
#define PRIORITY_H

template<class Object>
struct Node {
	Object entry;
	int priority;
	Node<Object> *next;

	Node();
	Node(Object, int);
};

template<class Object>
Node<Object>::Node()
{
	next = NULL;
}

template<class Object>
Node<Object>::Node(Object entry, int priority)
{
	Node<Object>::entry = entry;
	Node<Object>::priority = priority;
	Node<Object>::next = NULL;
}

template<class Object>
class PriorityQueue {	
private:
	Node<Object> *front;	
	int size;
public:
	explicit PriorityQueue() : front(NULL), size(0) {}

	void InsertElement(Object, int);
	Object RemoveTopElement();
	int Size() const;
	bool IsEmpty() const;
	void Clear();	

	~PriorityQueue();
};
#endif
