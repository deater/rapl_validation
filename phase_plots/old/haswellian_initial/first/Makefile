CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =

all:	convert references.eps

convert:	convert.o
	$(CC) $(LFLAGS) -o convert convert.o

convert.o:	convert.c
	$(CC) $(CFLAGS) -c convert.c

references.eps:	references.jgr
	jgraph < references.jgr > references.eps

clean:
	rm -f *~ *.o convert
