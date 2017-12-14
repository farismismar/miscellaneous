//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:        Operating Systems CS473
//--------------------------------------------------------------
// Main.cc
//--------------------------------------------------------------


#include <iostream>

using std::cout;
using std::endl;

#include "CPUSimulator.h"

int main()
{
  system("date");
  system("date > PA2TestData.output.txt");
  system("echo CS473 Programming Assignment 2 >> PA2TestData.output.txt");

  cout << "CS473 Programming Assignment 2" << endl << endl;

  CPUSimulator schedulingScheme1("FCFS");
  CPUSimulator schedulingScheme2("SJF");
  CPUSimulator schedulingScheme3("PRI");

  return 0;
}

