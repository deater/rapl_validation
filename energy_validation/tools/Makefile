CC = gcc
CFLAGS = -Wall -O2
LFLAGS =

all:	perf_dram_results dump_watts_multiple debounce_serial

perf_dram_results:	perf_dram_results.o
	$(CC) $(LFLAGS) -o perf_dram_results perf_dram_results.o

perf_dram_results.o:	perf_dram_results.c
	$(CC) $(CFLAGS) -c perf_dram_results.c

dump_watts_multiple:	dump_watts_multiple.o
	$(CC) $(LFLAGS) -o dump_watts_multiple dump_watts_multiple.o

dump_watts_multiple.o:	dump_watts_multiple.c
	$(CC) $(CFLAGS) -c dump_watts_multiple.c

debounce_serial:	debounce_serial.o
	$(CC) $(LFLAGS) -o debounce_serial debounce_serial.o

debounce_serial.o:	debounce_serial.c
	$(CC) $(CFLAGS) -c debounce_serial.c

clean:
	rm -f perf_dram_results dump_watts_multiple debounce_serial *.o *~
