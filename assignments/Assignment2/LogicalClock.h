//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #2: A Simple CPU Scheduling Simulator
//--------------------------------------------------------------
//
/**  LogicalClock.h

**/

#ifndef LOGICAL_H
#define LOGICAL_H

class LogicalClock {
	friend class CPUSimulator;
private:
	static int timer;
public:
	LogicalClock();
	static void incrementClock(void);
	static int getCurrentTime(void);
};
#endif
