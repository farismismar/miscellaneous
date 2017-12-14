//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  MMSimulator.cc

**/

#include "MMSimulator.h"
#include "Statistics.h"
#include "LogicalClock.h"
#include "FrameData.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

MMSimulator::MMSimulator(const char *algorithm, int pageCount, const char *fileName)
{
	// check for possible user-errors. . .
	if (pageCount != 4 && pageCount != 8) {
		cout << endl << "Sorry, this program is intended to be used for a page count of 4 or 8." << endl;
		exit(-1);
	}

	// initialize the data structures. . .
	FrameData::setSize(pageCount);

	MMSimulator::pageCount = pageCount;

	pageFaultsDone = totalPageReferences = 0;

	// empty all pages. . .
	for (int i = 0; i < pageCount; i++)
		FrameData::pages[i] = 0;

	// read the file. . .
	Input::getInformation(fileName);

	cout << endl << endl << endl << algorithm << " Memory Management Scheduling Simulation";
	cout << endl << endl << "  Final Frames Contents:" << endl << endl;

	if (strcmp(algorithm, "FIFO") == 0)
		FIFO();
	else if (strcmp(algorithm, "LRU") == 0)
		LRU();
	else if (strcmp(algorithm, "MFU") == 0)
		MFU();
	else {
		cout << "No such scheduling algorithm." << endl;
		exit(-1);
	}
	
	displayPages();
	cout << endl << endl << endl;

	totalPageReferences = frameCount;
	Statistics::showStatistics(totalPageReferences, pageFaultsDone);
}

bool MMSimulator::inMem(int frame) const
{
  int i = 0;

	for (; i < pageCount; i++)		
		if (frame == FrameData::pages[i]) {
			FrameData::inMemory[i] = true;
			return true;
		}
		
		FrameData::inMemory[i] = false;

	return false;
}

void MMSimulator::displayPages() const
{
	for (int i = 0; i < pageCount; i++)
		cout << i << ':' << setw(4) << FrameData::pages[i] << endl;
}

MMSimulator::~MMSimulator()
{
	delete [] pages;
	delete [] frames;
}

void MMSimulator::FIFO()
{
	if (FrameData::pages == NULL) return;

	// now start the simulation as FIFO
	int pageIndex = 0;
	for (int frameIndex = 0; frameIndex < frameCount; frameIndex++) {
		if (!inMem(frames[frameIndex])) {
			pageFaultsDone++;
			FrameData::pages[pageIndex] = frames[frameIndex];

			// move pointer to the next location
			pageIndex = (pageIndex + 1) % pageCount;
		}	
	}
}
		
void MMSimulator::LRU()
{	
	if (FrameData::pages == NULL) return;

	LogicalClock::timer = 0;

	// now start the simulation as LRU
	int pageIndex = 0;
	int leastRecentIndex;
	
	for (int frameIndex = 0; frameIndex < frameCount; frameIndex++) {
		if (inMem(frames[frameIndex])) {
			// just update the timeStamp of the page map table
			for (int x = 0; x < pageCount; x++)
				if (FrameData::pages[x] == frames[frameIndex]) {
					FrameData::timeStamp[x] = LogicalClock::getCurrentTime();
					break;
				}

			LogicalClock::incrementClock();
		}
		else {
			// raise a page-fault trap:
			pageFaultsDone++;

			if (pageFaultsDone <= pageCount) {
				// fill without using the algorithm:
				// assign pageIndex to its logical memory map table entry
				FrameData::pages[pageIndex] = frames[frameIndex];
				FrameData::timeStamp[pageIndex] = LogicalClock::getCurrentTime();
				LogicalClock::incrementClock();
				pageIndex++;
			}
			else {
				// fill according to algorithm:
				leastRecentIndex = 0;
				for (int x = 1; x < pageCount; x++)
					if (FrameData::timeStamp[x] < FrameData::timeStamp[leastRecentIndex])
						leastRecentIndex = x;
				pageIndex = leastRecentIndex;
				
				// assign pageIndex to its logical memory map table entry
				FrameData::pages[pageIndex] = frames[frameIndex];
				FrameData::timeStamp[pageIndex] = LogicalClock::getCurrentTime();

				LogicalClock::incrementClock();
			}
		}
	}
}

void MMSimulator::MFU()
{
	if (FrameData::pages == NULL) return;	
	
	// now start the simulation as MFU
	int pageIndex = 0;
	int mostFreqIndex;
	
	for (int frameIndex = 0; frameIndex < frameCount; frameIndex++) {
		if (inMem(frames[frameIndex]))  {
			// just update the count of the page map table
			for (int x = 0; x < pageCount; x++)
				if (FrameData::pages[x] == frames[frameIndex]) {
					FrameData::count[x]++;
					break;
				}
		}	
		else {			
			// raise a page-fault trap:
			pageFaultsDone++;

			if (pageFaultsDone <= pageCount) {
				// fill without using the algorithm:
				// assign pageIndex to its logical memory map table entry
				FrameData::pages[pageIndex] = frames[frameIndex];
				FrameData::count[pageIndex]++;
				pageIndex++;
			}
			else {
				// fill according to algorithm:
				mostFreqIndex = 0;
				for (int x = 1; x < pageCount; x++)
					if (FrameData::count[x] > FrameData::count[mostFreqIndex])
						mostFreqIndex = x;
				pageIndex = mostFreqIndex;
				
				// assign pageIndex to its logical memory map table entry				
				FrameData::count[pageIndex] = 1;				
				FrameData::pages[pageIndex] = frames[frameIndex];			
			}
		}
	}
}
