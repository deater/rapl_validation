CC = gcc
CFLAGS = -Wall -O2
LFLAGS =

all:	perf_dram_results \
	dump_watts_ddr3 dump_watts_ddr4 \
	dump_trace_daq_ddr4 \
	debounce_serial perf_dram_results_new

perf_dram_results:	perf_dram_results.o
	$(CC) $(LFLAGS) -o perf_dram_results perf_dram_results.o

perf_dram_results.o:	perf_dram_results.c
	$(CC) $(CFLAGS) -c perf_dram_results.c

perf_dram_results_new:	perf_dram_results_new.o
	$(CC) $(LFLAGS) -o perf_dram_results_new perf_dram_results_new.o

perf_dram_results_new.o:	perf_dram_results_new.c
	$(CC) $(CFLAGS) -c perf_dram_results_new.c



dump_watts_ddr3:	dump_watts_ddr3.o
	$(CC) $(LFLAGS) -o dump_watts_ddr3 dump_watts_ddr3.o

dump_watts_ddr3.o:	dump_watts_ddr3.c
	$(CC) $(CFLAGS) -c dump_watts_ddr3.c


dump_watts_ddr4:	dump_watts_ddr4.o
	$(CC) $(LFLAGS) -o dump_watts_ddr4 dump_watts_ddr4.o

dump_watts_ddr4.o:	dump_watts_ddr4.c
	$(CC) $(CFLAGS) -c dump_watts_ddr4.c


dump_trace_daq_ddr4:	dump_trace_daq_ddr4.o
	$(CC) $(LFLAGS) -o dump_trace_daq_ddr4 dump_trace_daq_ddr4.o

dump_trace_daq_ddr4.o:	dump_trace_daq_ddr4.c
	$(CC) $(CFLAGS) -c dump_trace_daq_ddr4.c



debounce_serial:	debounce_serial.o
	$(CC) $(LFLAGS) -o debounce_serial debounce_serial.o

debounce_serial.o:	debounce_serial.c
	$(CC) $(CFLAGS) -c debounce_serial.c

clean:
	rm -f perf_dram_results_new perf_dram_results dump_watts_ddr3 dump_watts_ddr4 dump_trace_daq_ddr4 debounce_serial *.o *~
