All:	Simulate

Simulate:	ProcessControlBlock.o LogicalClock.o Statistics.o Input.o CPUSimulator.o Main.o
	g++ -Wall Main.o CPUSimulator.o ProcessControlBlock.o LogicalClock.o Statistics.o Input.o -o Simulate

Main.o:	Main.cc
	g++ -c -Wall Main.cc -o Main.o

ProcessControlBlock.o:	ProcessControlBlock.h ProcessControlBlock.cc
	g++ -c -Wall ProcessControlBlock.cc -o ProcessControlBlock.o

LogicalClock.o:	LogicalClock.h LogicalClock.cc
	g++ -c -Wall LogicalClock.cc -o LogicalClock.o

Statistics.o:	Statistics.h Statistics.cc
	g++ -c -Wall Statistics.cc -o Statistics.o

Input.o:	Input.h Input.cc
	g++ -c -Wall Input.cc -o Input.o

CPUSimulator.o:	CPUSimulator.h CPUSimulator.cc
	g++ -c -Wall CPUSimulator.cc -o CPUSimulator.o

run:	Simulate
	./Simulate

clean:
	rm -f *.o Simulate
