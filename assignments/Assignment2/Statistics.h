//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #2: A Simple CPU Scheduling Simulator
//--------------------------------------------------------------
//
/**  Statistics.h

**/
#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <iomanip>

using std::ostream;
using std::endl;
using std::ios;
using std::setprecision;
using std::setiosflags;

class Statistics {
	friend class CPUSimulator;
private:
	static int timeSteps;
	static int waitTime;
	static int idleTime;
public:
	Statistics();
	static void doStatistics(ostream &, int);
	static void clear(void);
};
#endif
