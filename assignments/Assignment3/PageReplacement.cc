//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  PageReplacement.cc

**/

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

#include "MMSimulator.h"

int main(int argc, char *argv[])
{
  char *dataFile;       // Name of data file
	
  int  nFrames;         // Number of frames
	
  // Make sure that the Frames and name of the data file were supplied
  if (argc != 3)
    {
      cout << "Must supply Number of Frames and the data file name\n\n";
      exit(-1);
    }
  	
	
  // Now get the arguments
	
	
  nFrames = atoi(argv[1]);     //number of frames from the second argument
	
  if (nFrames == 0) {
    cout << "Must supply the Number of frames as second argument\n\n";
    exit(-1);
  }
	
	
  dataFile = argv[2];           // Datafile name
	
  cout << "CS473 Programming Assignment 3" << endl;
  cout << "Faris B. Mismar June 2003" << endl << endl;	
  cout << "Input File  :  " << dataFile << endl;
  cout << "No of Frames:  " << nFrames;

  // Now do the simulations
	
  MMSimulator *sim;
  sim = new MMSimulator ("FIFO", nFrames, dataFile);
  delete sim;
	
  sim = new MMSimulator ("LRU", nFrames, dataFile);
  delete sim;
	
  sim = new MMSimulator ("MFU", nFrames, dataFile);
  delete sim;
	
  return (0);
}
