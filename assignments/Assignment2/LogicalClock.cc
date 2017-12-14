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
