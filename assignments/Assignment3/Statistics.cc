//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  Statistics.cc

**/
#include "Statistics.h"

#include <iostream>

using std::cout;
using std::endl;

void Statistics::showStatistics(int totalPageRefs, int totalPageFaults)
{
	cout << "  Statistics:" << endl;
	cout << "    Total Page References:  " << totalPageRefs << endl;
    cout << "    Total Page Faults:  " << totalPageFaults << endl;
    cout << "    Page Fault Rate:  " << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(3) << (double)totalPageFaults / totalPageRefs << endl;
}
