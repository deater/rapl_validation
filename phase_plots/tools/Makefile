CC = gcc
CFLAGS = -O2 -Wall
LFLAGS =

all:	dump_ddr4_vdd dump_ddr4_vpp perf_rapl


dump_ddr4_vdd:	dump_ddr4_vdd.o
	$(CC) $(LFLAGS) -o dump_ddr4_vdd dump_ddr4_vdd.o

dump_ddr4_vdd.o:	dump_ddr4_vdd.c
	$(CC) $(CFLAGS) -c dump_ddr4_vdd.c


dump_ddr4_vpp:	dump_ddr4_vpp.o
	$(CC) $(LFLAGS) -o dump_ddr4_vpp dump_ddr4_vpp.o

dump_ddr4_vpp.o:	dump_ddr4_vpp.c
	$(CC) $(CFLAGS) -c dump_ddr4_vpp.c

perf_rapl:	perf_rapl.o
	$(CC) $(LFLAGS) -o perf_rapl perf_rapl.o

perf_rapl.o:	perf_rapl.c
	$(CC) $(CFLAGS) -c perf_rapl.c

clean:
	rm -f *~ *.o dump_ddr4_vdd dump_ddr4_vpp perf_rapl
