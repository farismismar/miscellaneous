//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  MMSimulator.h

**/
#ifndef MMSIMULATOR_H
#define MMSIMULATOR_H

#include "Input.h"
#include "FrameData.h"

class MMSimulator {
	friend class Input;
private:
	static FrameData *pages;
	static int *frames;
	static int pageFaultsDone;
	static int totalPageReferences;
	static int frameCount;		// in physical memory
	static int pageCount;		// in logical memory
public:
	explicit MMSimulator(const char *, int, const char *);
	void FIFO(void);
	void LRU(void);
	void MFU(void);
	void displayPages(void) const;
	bool inMem(int) const;
	~MMSimulator(void);
};

#endif
