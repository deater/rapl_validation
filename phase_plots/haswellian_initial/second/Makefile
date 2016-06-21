CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =

all:	convert-perf convert-daq

convert-perf:	convert-perf.o
	$(CC) $(LFLAGS) -o convert-perf convert-perf.o

convert-perf.o:	convert-perf.c
	$(CC) $(CFLAGS) -c convert-perf.c



convert-daq:	convert-daq.o
	$(CC) $(LFLAGS) -o convert-daq convert-daq.o

convert-daq.o:	convert-daq.c
	$(CC) $(CFLAGS) -c convert-daq.c



references.eps:	references.jgr
	jgraph < references.jgr > references.eps

clean:
	rm -f *~ *.o convert-perf convert-daq
