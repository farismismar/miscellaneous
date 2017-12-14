#include "LogicalClock.h"
#include "Statistics.h"
#include "CPUSimulator.h"
#include "Input.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using std::cout;
using std::ostream;
using std::endl;
using std::setw;
using std::string;
using std::fstream;

CPUSimulator::CPUSimulator(const char *algorithm)
{
	//fstream output;
	//output.open("PA2TestData.output.txt", ios::out | ios::app);
	
	doWork(algorithm, cout);	// print on the screen. . .
	//doWork(algorithm, output);	// write them to file. . .
	
	//output.close();
}

void CPUSimulator::centerPrintln(const char *msg, ostream &output) const
{
	int length = strlen(msg);
	// width is 80 columns, subtract from it the original length, then divide..
	int numOfSpaces = (80 - length) / 2;
	
	for (int i = 0; i < numOfSpaces; i++)
		output << ' ';
	
	output << msg << endl;
}

void CPUSimulator::doWork(const char *algorithm, ostream &output)
{
	// Starting up. . .
	string title = algorithm;
	title += " CPU Scheduling Simulation";
	
	output << endl << endl;
	
	// use string::c_str() to allow conversion to C-Strings. . .
	centerPrintln(title.c_str(), output);
	centerPrintln("Non-Preemptive", output);
	
	output << endl;
	
	output << "TimeDone" << setw(9) 
		<< "JobNo" << setw(9) 
		<< "AcctNo" << setw(9)
		<< "MaxTime" << setw(9)
		<< "ArrTim" << setw(9) 
		<< "WaitTim" << setw(9) 
		<< "ElapsTim" << endl;
	
	// Initialize parameters and data structures. . .
	ProcessControlBlock::clear();
	
	// Read and store input. . .
	Input::getInformation();
	
	// Initialize timer to zero. . .
	LogicalClock::timer = 0;
	
	int queueID;
	
	if (strcmp(algorithm, "FCFS") == 0)
		queueID = FCFS();
	else if (strcmp(algorithm, "SJF") == 0)
		queueID = SJF();
	else if (strcmp(algorithm, "PRI") == 0)
		queueID = PRI();
	else {
		cout << "No such a scheduling algorithm!" << endl;
		return;
	}
	
	int size = ProcessControlBlock::count;
	
	// before entering this portion, the entire queues must be ready
	// from the before initializing algorithms. . .
	
	while (!readyQueue[queueID].IsEmpty()) {
		// check for next job: if its arrivalTime is still late, add idle time.
		// reading the top element is done through removing it
		// and inserting it at a higher priority. . .
		ProcessNode *nextJob = readyQueue[queueID].RemoveTopElement();
		
		if (nextJob != NULL) {
			readyQueue[queueID].InsertElement(nextJob, 0);
			
			if (nextJob->arrivalTime > LogicalClock::getCurrentTime()) {
				// keep incrementing the clock until it has the value of the next arrivalTime
				// and meanwhile, CPU is idle.
				for (; (nextJob->arrivalTime - LogicalClock::getCurrentTime()); ) {
					Statistics::idleTime++;
					LogicalClock::incrementClock();
				}
				
			}
		}
		
		// carry current job to termination. . .
		ProcessNode *currentJob = readyQueue[queueID].RemoveTopElement();
		
		// calculate waitingTime that job will do, which is:
		if (currentJob->arrivalTime < LogicalClock::getCurrentTime()) {
			for (int i = 0; i < (LogicalClock::getCurrentTime() - 
				currentJob->arrivalTime); i++) {
				currentJob->waitingTime++;
				Statistics::waitTime++;				
			}			
		}
		
		// execute the job after calcuating the waitingTime. . .
		for (int i = 0; i < currentJob->burstTime; i++)
			LogicalClock::incrementClock();
		// execution terminated.
		
		// calculate the elapsedTime of a job. . .
		currentJob->elapsedTime = currentJob->waitingTime + currentJob->burstTime;
		
		output << setw(8) << LogicalClock::getCurrentTime()
			<< setw(9) << currentJob->jobNumber
			<< setw(9) << currentJob->accountNumber
			<< setw(9) << currentJob->burstTime
			<< setw(9) << currentJob->arrivalTime
			<< setw(9) << currentJob->waitingTime
			<< setw(9) << currentJob->elapsedTime
			<< endl;
	}
	// Termination: cleanup and final statistics
	Statistics::timeSteps = LogicalClock::getCurrentTime();
	Statistics::doStatistics(output, size);
	
	// clean up. . .
	// Cleanup is done by automatic invocation of destructors. .
}

int CPUSimulator::FCFS()
{
	int size = ProcessControlBlock::count;
	
	// time simulations start from t == 1
	Statistics::clear();
	
	// put jobs in readyQueue according to arrivalTime:
	for (int jobNum = 1; jobNum <= size; jobNum++) {
		ProcessNode *job = ProcessControlBlock::getProcess(jobNum);
		readyQueue[0].InsertElement(job, job->arrivalTime);
	}
	
	return (0);
}

int CPUSimulator::SJF()
{
	int size = ProcessControlBlock::count;
	
	// time simulations start from t == 1
	Statistics::clear();
	
	PriorityQueue<ProcessNode *> burstQueue;
	PriorityQueue<ProcessNode *> temp;
	
	// put jobs in burst according to burstTime:
	for (int jobNum = 1; jobNum <= size; jobNum++) {
		ProcessNode *job = ProcessControlBlock::getProcess(jobNum);
		burstQueue.InsertElement(job, job->burstTime);
	}
	
	int dummyClock = 1;
	while (!burstQueue.IsEmpty()) {		
		ProcessNode *currentJob = burstQueue.RemoveTopElement();
		
		// decide which job to execute:
		while(!burstQueue.IsEmpty() && currentJob->arrivalTime > dummyClock) {
			temp.InsertElement(currentJob, currentJob->burstTime);
			currentJob = burstQueue.RemoveTopElement();
		}
		
		// execute the job after calcuating the waitingTime. . .
		for (int i = 0; i < currentJob->burstTime; i++)
			dummyClock++;
		
		//-----------------------------------------------------------------------//
		// Now move all processes back to burstQueue
		//-----------------------------------------------------------------------//
		
		while (!temp.IsEmpty())	{
			ProcessNode *hold = temp.RemoveTopElement();
			burstQueue.InsertElement(hold, hold->burstTime);
		}
		
		readyQueue[1].InsertElement(currentJob, dummyClock);
	}
	
	// perform a final pass to see if there are two consecutive jobs having the same arrivalTime
	ProcessNode *prevJob = readyQueue[1].RemoveTopElement();
	ProcessNode *nextJob = readyQueue[1].RemoveTopElement();
	
	temp.Clear();
	
	for (int i = 0; i < size; i++) {
		if (nextJob == NULL) {
			temp.InsertElement(prevJob, 1);
			break;
		}
		// either enter two jobs as they are, or swapped
		if (prevJob->arrivalTime != nextJob->arrivalTime) {
			// enter them in their original order
			temp.InsertElement(prevJob, 1);						
			prevJob = nextJob;
		}
		else {
			if (prevJob->burstTime <= nextJob->burstTime) {
				temp.InsertElement(prevJob, 1);						
				prevJob = nextJob;
			} 
			
			else
				// enter them in the swapped order
				temp.InsertElement(nextJob, 1);			
		}		
		nextJob = readyQueue[1].RemoveTopElement();		
	}
	
	readyQueue[1].Clear();
	
	while (!temp.IsEmpty()) {
		ProcessNode *x = temp.RemoveTopElement();
		readyQueue[1].InsertElement(x, 1);
	}
	
	return (1);
}

int CPUSimulator::PRI()
{
	int size = ProcessControlBlock::count;
	
	// time simulations start from t == 1
	Statistics::clear();
	
	PriorityQueue<ProcessNode *> priQueue;
	PriorityQueue<ProcessNode *> temp;
	
	// put jobs in priQueue according to accountNumber / 1000:
	for (int jobNum = 1; jobNum <= size; jobNum++) {
		ProcessNode *job = ProcessControlBlock::getProcess(jobNum);
		priQueue.InsertElement(job, job->accountNumber / 1000);
	}
	
	int dummyClock = 1;
	while (!priQueue.IsEmpty()) {		
		ProcessNode *currentJob = priQueue.RemoveTopElement();
		
		// decide which job to execute:
		while(!priQueue.IsEmpty() && currentJob->arrivalTime > dummyClock) {
			temp.InsertElement(currentJob, currentJob->accountNumber / 1000);
			currentJob = priQueue.RemoveTopElement();
		}
		
		// execute the job after calculating the waitingTime. . .
		for (int i = 0; i < currentJob->burstTime; i++)
			dummyClock++;
		
		//-----------------------------------------------------------------------
		// Now move all processes back to priQueue
		//-----------------------------------------------------------------------
		
		while (!temp.IsEmpty())	{
			ProcessNode *hold = temp.RemoveTopElement();
			priQueue.InsertElement(hold, hold->accountNumber / 1000);
		}
		
		readyQueue[2].InsertElement(currentJob, dummyClock);
	}
	
	// perform a final pass to see if there are two consecutive jobs having the same arrivalTime
	ProcessNode *prevJob = readyQueue[2].RemoveTopElement();
	ProcessNode *nextJob = readyQueue[2].RemoveTopElement();
	
	temp.Clear();
	
	for (int i = 0; i < size; i++) {
		if (nextJob == NULL) {
			temp.InsertElement(prevJob, 1);
			break;
		}
		// either enter two jobs as they are, or swapped
		if (prevJob->arrivalTime != nextJob->arrivalTime) {
			// enter them in their original order
			temp.InsertElement(prevJob, 1);						
			prevJob = nextJob;
		}
		else {
			if (prevJob->accountNumber / 1000 <= nextJob->accountNumber / 1000) {
				temp.InsertElement(prevJob, 1);						
				prevJob = nextJob;
			} 	
			else
				// enter them in the swapped order
				temp.InsertElement(nextJob, 1);			
		}		
		
		nextJob = readyQueue[2].RemoveTopElement();		
	}
	
	readyQueue[2].Clear();
	
	while (!temp.IsEmpty()) {
		ProcessNode *x = temp.RemoveTopElement();
		readyQueue[2].InsertElement(x, 1);
	}
	
	return (2);
}
