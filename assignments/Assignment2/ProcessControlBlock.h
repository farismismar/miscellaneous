//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #2: A Simple CPU Scheduling Simulator
//--------------------------------------------------------------
//
/**  ProcessControlBlock.h

**/

#ifndef PCB_H
#define PCB_H

#include "Statistics.h"

struct ProcessNode {
	ProcessNode *next;
	int jobNumber;
	int accountNumber;
	int priorityCode;
	int burstTime;
	int arrivalTime;
	int waitingTime;
	int elapsedTime;	
	ProcessNode() : next(NULL) {}
};

class ProcessControlBlock {
	friend class CPUSimulator;	
private:
	static ProcessNode *head;
	static int count;
public:
	ProcessControlBlock();
	static void addProcess(int, int, int, int);
	static void removeProcess(int = -1);
	static ProcessNode *getProcess(int);
	static void clear();
	static bool empty();
	~ProcessControlBlock();
};
#endif
