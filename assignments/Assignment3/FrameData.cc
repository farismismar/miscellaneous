//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  FrameData.cc

**/

#include "FrameData.h"

void FrameData::setSize(int n)
{
	timeStamp = new int [n];
	pages = new int [n];
	inMemory = new bool [n];
	count = new int [n];

	// initialize all structures here. . .
	for (int i = 0; i < n; i++)
		timeStamp[i] = pages[i] = count[i] = inMemory[i] = 0;
}

FrameData::~FrameData()
{
	delete [] timeStamp;
	delete [] pages;
	delete [] inMemory;
	delete [] count;
}
