//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  Input.cc

**/
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;
using std::ios;

#include "Input.h"
#include "MMSimulator.h"
#include "FrameData.h"

int MMSimulator::frameCount = 0;
int MMSimulator::pageCount = 0;
int MMSimulator::pageFaultsDone = 0;
int MMSimulator::totalPageReferences = 0;

int *MMSimulator::frames = NULL;
FrameData *MMSimulator::pages = NULL;

int *FrameData::pages = NULL;
int *FrameData::timeStamp = NULL;
int *FrameData::count = NULL;
bool *FrameData::inMemory = NULL;

Input::Input()
{}

void Input::getInformation(const char *fileName)
{
	fstream fileHandle;

	// open file for reading purposes
	fileHandle.open(fileName, ios::in);

	if (!fileHandle) {
		cout << endl << "File error or file doesn't exist." << endl;
		exit(-1);
	}

	// read the entire file into the reference array. . .

	int frameNumber = -1;
	for (; !fileHandle.eof(); frameNumber++) {
		int dum;
		fileHandle >> dum;
	} 

	MMSimulator::frameCount = frameNumber;
	MMSimulator::frames = new int [frameNumber];
	
	// reposition file pointer to the beginning of file. . .
	fileHandle.clear();
	fileHandle.seekg(0);

	for (int i = 0; i < frameNumber; i++)
		fileHandle >> MMSimulator::frames[i];

	fileHandle.close();
}
