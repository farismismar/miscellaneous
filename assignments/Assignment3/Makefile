Program:	PageReplacement

PageReplacement:	Input.o LogicalClock.o FrameData.o MMSimulator.o Statistics.o PageReplacement.o
	g++ -Wall Input.o LogicalClock.o FrameData.o MMSimulator.o Statistics.o PageReplacement.o -o PageReplacement

Input.o:	Input.cc Input.h
	g++ -c -Wall Input.cc -o Input.o

LogicalClock.o:	LogicalClock.cc LogicalClock.h
	g++ -c -Wall LogicalClock.cc -o LogicalClock.o

MMSimulator.o:	MMSimulator.cc MMSimulator.h
	g++ -c -Wall MMSimulator.cc -o MMSimulator.o

Statistics.o:	Statistics.cc Statistics.h
	g++ -c -Wall Statistics.cc -o Statistics.o

FrameData.o:	FrameData.cc FrameData.h
	g++ -c -Wall FrameData.cc -o FrameData.o

PageReplacement.o:	PageReplacement.cc
	g++ -c -Wall PageReplacement.cc -o PageReplacement.o

clean:
	rm -rf *.o PageReplacement

