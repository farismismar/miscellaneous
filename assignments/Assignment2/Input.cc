#include "Input.h"
#include "ProcessControlBlock.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;
using std::ios;

int Input::jobs = 0;

Input::Input()
{}

void Input::getInformation()
{
	fstream fileHandle;
	
	fileHandle.open("PA2TestData.txt", ios::in);	
	
	if (!fileHandle) {
		cout << "File error or file doesn't exist." << endl;
		exit(-1);
	}
	
	int i = -1;
	for (; !fileHandle.eof(); i++) {
		int temp;
		fileHandle >> temp >> temp >> temp;		
	}
	
	// reposition file pointer back to the beginning of file.
	fileHandle.clear();
	fileHandle.seekg(0);

	// fill in the list with information
	for (int j = 1; j <= i; j++) {
		int a, b, at;
		// Create a ProcessNode. . .
		fileHandle >> a >> b >> at;	
		ProcessControlBlock::addProcess(a, b, at, j);
	}
	
	fileHandle.close();
}
