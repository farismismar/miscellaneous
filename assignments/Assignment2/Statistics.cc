#include "Statistics.h"

Statistics::Statistics()
{}

void Statistics::doStatistics(ostream &output, int n)
{
	output << "Statistics:" << endl << endl;

	output << " Number of jobs processed:  " << n << endl;
	output << " Number of time steps:  " << timeSteps <<  endl;
	
	output << endl;

	output << " Total Wait Time:  " << waitTime << endl;
	output << " Average Wait Time:  " << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(3) << (double)waitTime / n << endl;
	output << endl;

	output << " Total Idle Time:  " << (idleTime + 1) << endl;

	output << endl;
}

void Statistics::clear()
{
	idleTime = waitTime = timeSteps = 0;
}

int Statistics::timeSteps = 0;
int Statistics::waitTime = 0;
int Statistics::idleTime = 0;
