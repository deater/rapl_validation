CC = gcc
CFLAGS = -Wall -O2
LFLAGS =

all:	toggle_rts toggle_dtr

toggle_rts:	toggle_rts.o
	$(CC) $(LFLAGS) -o toggle_rts toggle_rts.o

toggle_rts.o:	toggle_rts.c
	$(CC) $(CFLAGS) -c toggle_rts.c

toggle_dtr:	toggle_dtr.o
	$(CC) $(LFLAGS) -o toggle_dtr toggle_dtr.o

toggle_dtr.o:	toggle_dtr.c
	$(CC) $(CFLAGS) -c toggle_dtr.c


clean:	
	rm -f *~ *.o toggle_rts toggle_dtr
