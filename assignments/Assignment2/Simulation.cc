//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #2: A Simple CPU Scheduling Simulator
//--------------------------------------------------------------
//
/**  Simulation.cc

**/

#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;

#include "CPUSimulator.h"

int main()
{
	//  system("date");
	//  system("date > PA2TestData.output.txt");
	//  system("echo CS473 Programming Assignment 2 >> PA2TestData.output.txt");
	
	cout << "CS473 Programming Assignment 2" << endl;	
	
	CPUSimulator simulation1("FCFS");
	CPUSimulator simulation2("SJF");
	CPUSimulator simulation3("PRI");
	
	return (0);
}
