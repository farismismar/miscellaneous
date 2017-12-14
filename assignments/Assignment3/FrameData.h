//--------------------------------------------------------------
// Name:   MISMAR, FARIS BASSAM
// SID:    0002774
// Sec:    1	(10 - 11)
//
// Course:     Operating Systems CS473
// Assignment: Assignment #3: Page Replacement Simulator
//--------------------------------------------------------------
//
/**  FrameData.h

**/

#ifndef FRAMEDATA_H
#define FRAMEDATA_H

class FrameData {
	friend class Input;
	friend class MMSimulator;
private:
	static int *timeStamp;
	static int *count;
	static bool *inMemory;
	static int *pages;
public:
	static void setSize(int n);
	~FrameData(void);
};

#endif
