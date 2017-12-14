#include "ProcessControlBlock.h"

ProcessControlBlock::ProcessControlBlock()
{}

void ProcessControlBlock::addProcess(int a, int b, int at, int i)
{
	ProcessNode *newProcess = new ProcessNode();
	
	if (newProcess == NULL) return;
	
	newProcess->accountNumber = a;
	newProcess->burstTime = b;
	newProcess->arrivalTime = at;
	newProcess->jobNumber = i;
	newProcess->elapsedTime = 0;
	newProcess->waitingTime = 0;
	newProcess->priorityCode = 0;
	
	if (head == NULL) head = newProcess;
	else {
		ProcessNode *current = head;
		for (; current->next != NULL; current = current->next)
			;
		current->next = newProcess;
	}
	count++;
}

void ProcessControlBlock::removeProcess(int jobNumber)
{
	if (empty()) return;

	if (jobNumber == -1) {
		ProcessNode *oldHead = head;
		head = head->next;
		delete oldHead;
		count--;
		return;
	}

	// if the element is the first element:
	if (head->jobNumber == jobNumber) {
		ProcessNode *newHead = head->next;
		delete head;
		head = newHead;
		count--;
		return;
	}

	for (ProcessNode *currentNode = head; currentNode->next != NULL; currentNode = currentNode->next) {
		ProcessNode *nextNode = currentNode->next;

		if (nextNode->jobNumber == jobNumber) {
			ProcessNode *temp = nextNode;
			currentNode->next = temp->next;
			delete temp;
			count--;
			return;
		}
	}
}

inline bool ProcessControlBlock::empty()
{
	return (head == NULL);
}

ProcessNode *ProcessControlBlock::getProcess(int jobNo)
{
	// give it the jobNumber to return a pointer to the node itself
	for (ProcessNode *x = head; x != NULL; x = x->next)
		if (x->jobNumber == jobNo) return x;

	return (NULL);
}

void ProcessControlBlock::clear()
{
	while (count > 0)		
		removeProcess();	
}

ProcessControlBlock::~ProcessControlBlock()
{	
	clear();	
}

// Initialize the static variables. . .
int ProcessControlBlock::count = 0;
ProcessNode *ProcessControlBlock::head = NULL;
