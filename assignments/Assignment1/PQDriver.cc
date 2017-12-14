//--------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #1: Priority Queues
//--------------------------------------------------------
//
/**  PQDriver.cc

	A driver to test a C++ priority queue template class

	The PQ class must be named PriorityQueue
	It must have the following methods:

	   PriorityQueue():  the constructor
	   ~PriorityQueue():  the destructor

	   void InsertElement(Object item, int priority):
			to add an element to the PQ
	   BaseType RemoveTopElement():
			to remove the top element of the PQ
			(the one with highest priority)

	   int Size():  the number of elements in the PQ
	   int IsEmpty():  true if the PQ contains no elements
	   void Clear():  removes all elements from the PQ

	We assume that the integer with the lowest value
		has the highest priority
	I.e. given the list 8,2,7,5,3 -- the priority designates
		that 2 is first, 3 is next, followed by 5, 7, and 8
**/

#include <iostream>
using namespace std;

#include "PriorityQueue.h"
#include "PriorityQueue.cc"

// Tests the PriorityQueue class
int main ()
{
	// Starts test by printing out heading
	cout << "Start PQ Test" << endl;
	cout << endl;
	
	// Creates a new PriorityQueue object for strings
	PriorityQueue<char *> pQ;
	cout << "Constructed PQ" << endl;
	
	// Tests IsEmpty function  (is PQ empty?)
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	
	// Tests Size function  (how many elements in PQ?)
	cout <<  "Size of PQ is " <<  pQ.Size() << endl ;
	cout <<  endl ;
	
	// Inserts a single string element: "first"
	pQ.InsertElement("first", 2);
	cout <<  "Add element 'first' at priority 2" << endl ;
	// Repeats IsEmpty and Size tests
	//      to check if element inserted
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout <<  "Size of PQ is " <<  pQ.Size() << endl ;
	cout <<  endl ;
	
	// Removes and returns top element of PQ
	char * e1 = pQ.RemoveTopElement();
	// Repeats IsEmpty and Size tests
	//      to check if element returned and deleted
	cout  << "Remove element with highest priority:  " << e1 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	// Cleans out current PQ contents
	pQ.Clear();
	cout  << "Clear out PQ" << endl ;
	// Repeats IsEmpty and Size tests to doublecheck
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	// Inserts five elements with different priorites
	//     checking size of PQ after each insert
	pQ.InsertElement("P7", 7);
	cout  << "Add element 'P7' at priority 7" << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	pQ.InsertElement("P6a", 6);
	cout  << "Add element 'P6a' at priority 6" << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	
	pQ.InsertElement("P4", 4);
	cout  << "Add element 'P4' at priority 4" << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	pQ.InsertElement("P6b", 6);
	cout  << "Add element 'P6b' at priority 6" << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	pQ.InsertElement("P5", 5);
	cout  << "Add element 'P5' at priority 5" << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	// Removes all five elements with different priorites
	//     checking size of PQ after each insert and
	//     checking that order of returns matches priorities
	char * e2 = pQ.RemoveTopElement();
	cout  << "Remove element with highest priority:  " << e2 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	char * e3 = pQ.RemoveTopElement();
	cout  << "Remove element with highest priority:  " << e3 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	char * e4 = pQ.RemoveTopElement();
	cout  << "Remove element with highest priority:  " << e4 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	char * e5 = pQ.RemoveTopElement();
	cout  << "Remove element with highest priority:  " << e5 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	char * e6 = pQ.RemoveTopElement();
	cout  << "Remove element with highest priority:  " << e6 << endl ;
	if (pQ.IsEmpty())
		cout <<  "PQ is empty:  true  " << endl ;
	else
		cout <<  "PQ is empty:  false  " << endl ;
	cout  << "Size of PQ is " <<  pQ.Size() << endl ;
	cout  << endl ;
	
	// Test is complete
	cout << "End PQ Test" << endl;
	
	return (0);
}
