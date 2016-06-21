CC = gcc
CFLAGS = -O2 -Wall -g
LFLAGS =

all:	find-pulse \
	generate-cpi generate-wup generate-cache-misses \
	generate-package-rapl generate-dram-rapl generate-gpu-rapl generate-cores-rapl \
	generate-dram generate-cpu \
	energy-dram-daq energy-dram-rapl \
	energy-from-plot


convert-perf:	convert-perf.o
	$(CC) $(LFLAGS) -o convert-perf convert-perf.o

convert-perf.o:	convert-perf.c
	$(CC) $(CFLAGS) -c convert-perf.c



convert-daq:	convert-daq.o
	$(CC) $(LFLAGS) -o convert-daq convert-daq.o

convert-daq.o:	convert-daq.c
	$(CC) $(CFLAGS) -c convert-daq.c


find-pulse:	find-pulse.o
	$(CC) $(LFLAGS) -o find-pulse find-pulse.o

find-pulse.o:	find-pulse.c
	$(CC) $(CFLAGS) -c find-pulse.c



generate-cache-misses:	generate-cache-misses.o
	$(CC) $(LFLAGS) -o generate-cache-misses generate-cache-misses.o

generate-cache-misses.o:	generate-cache-misses.c
	$(CC) $(CFLAGS) -c generate-cache-misses.c



generate-cpu:	generate-cpu.o
	$(CC) $(LFLAGS) -o generate-cpu generate-cpu.o

generate-cpu.o:	generate-cpu.c
	$(CC) $(CFLAGS) -c generate-cpu.c


generate-dram:	generate-dram.o
	$(CC) $(LFLAGS) -o generate-dram generate-dram.o

generate-dram.o:	generate-dram.c
	$(CC) $(CFLAGS) -c generate-dram.c


energy-dram-daq:	energy-dram-daq.o
	$(CC) $(LFLAGS) -o energy-dram-daq energy-dram-daq.o

energy-dram-daq.o:	energy-dram-daq.c
	$(CC) $(CFLAGS) -c energy-dram-daq.c



energy-dram-rapl:	energy-dram-rapl.o
	$(CC) $(LFLAGS) -o energy-dram-rapl energy-dram-rapl.o

energy-dram-rapl.o:	energy-dram-rapl.c
	$(CC) $(CFLAGS) -c energy-dram-rapl.c


energy-gpu-rapl:	energy-gpu-rapl.o
	$(CC) $(LFLAGS) -o energy-gpu-rapl energy-gpu-rapl.o

energy-gpu-rapl.o:	energy-gpu-rapl.c
	$(CC) $(CFLAGS) -c energy-gpu-rapl.c


energy-from-plot:	energy-from-plot.o
	$(CC) $(LFLAGS) -o energy-from-plot energy-from-plot.o

energy-from-plot.o:	energy-from-plot.c
	$(CC) $(CFLAGS) -c energy-from-plot.c



generate-dram-rapl:	generate-dram-rapl.o
	$(CC) $(LFLAGS) -o generate-dram-rapl generate-dram-rapl.o

generate-dram-rapl.o:	generate-dram-rapl.c
	$(CC) $(CFLAGS) -c generate-dram-rapl.c


generate-cores-rapl:	generate-cores-rapl.o
	$(CC) $(LFLAGS) -o generate-cores-rapl generate-cores-rapl.o

generate-cores-rapl.o:	generate-cores-rapl.c
	$(CC) $(CFLAGS) -c generate-cores-rapl.c




generate-package-rapl:	generate-package-rapl.o
	$(CC) $(LFLAGS) -o generate-package-rapl generate-package-rapl.o

generate-package-rapl.o:	generate-package-rapl.c
	$(CC) $(CFLAGS) -c generate-package-rapl.c



generate-wup:	generate-wup.o
	$(CC) $(LFLAGS) -o generate-wup generate-wup.o

generate-wup.o:	generate-wup.c
	$(CC) $(CFLAGS) -c generate-wup.c



references.eps:	references.jgr
	jgraph < references.jgr > references.eps

clean:
	rm -f *~ *.o convert-perf convert-daq find-pulse \
		generate-cpi generate-wup generate-cache-misses \
		generate-package-rapl generate-dram-rapl generate-gpu-rapl generate-cores-rapl \
		generate-dram generate-cpu \
		energy-dram-daq energy-dram-rapl \
		energy-from-plot
