//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  LogicalClock.cc

**/
#include "LogicalClock.h"

LogicalClock::LogicalClock() 
{}

void LogicalClock::incrementClock()
{
	timer++;
}

int LogicalClock::getCurrentTime()
{
	return (timer);
}

// initialize timer to zero. . .
int LogicalClock::timer = 0;
