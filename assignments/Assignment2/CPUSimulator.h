//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #2: A Simple CPU Scheduling Simulator
//--------------------------------------------------------------
//
/**  CPUSimulator.h

**/
#ifndef CPUSIM_H
#define CPUSIM_H

#include <iostream>
using std::ostream;

#include "ProcessControlBlock.h"
#include "../assignment1/PriorityQueue.h"
#include "../assignment1/PriorityQueue.cc"

class CPUSimulator {	
private:
	void centerPrintln(const char *, ostream &) const;	
	void doWork(const char *, ostream &);
	int FCFS(void);
	int SJF(void);
	int PRI(void);
	PriorityQueue<ProcessNode *> readyQueue[3];
public:
	explicit CPUSimulator(const char *);
};
#endif
