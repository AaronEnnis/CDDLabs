CC=g++
CFLAGS= -std=c++11 -pthread -I.

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) 

ALL: Semaphore.o signal.o
	$(CC) -o signal Semaphore.o signal.o $(CFLAGS) 

CLEAN:
	rm *.o
