#!/bin/sh
for i in `seq 1 10`; do /home/vince/research/linux-kernel/linux-4.1.5/tools/perf/perf stat -a -e cycles,instructions,cache-misses,cache-references,uncore_imc/data_reads/,uncore_imc/data_writes/,power/energy-cores/,power/energy-pkg/,power/energy-ram/ /home/vince/research/power-measurement/power_benchmarks/stream-5.10/stream_omp 2> stream.perf.$i 1> stream.stdio.$i ; echo $i; done
