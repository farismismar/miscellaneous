all:	PQDriver

PQDriver:	PQDriver.o PriorityQueue.o
	g++ -Wall PQDriver.o PriorityQueue.o -o PQDriver

PQDriver.o:	PQDriver.cc
	g++ -Wall -c PQDriver.cc -o PQDriver.o

PriorityQueue.o:	PriorityQueue.h PriorityQueue.cc
	g++ -Wall -c PriorityQueue.cc -o PriorityQueue.o

run:	PQDriver
	./PQDriver

clean:
	rm -f *.o PQDriver
