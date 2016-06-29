#!/bin/sh
for i in `seq 1 10`; do /home/vince/research/linux-kernel/linux-4.1.5/tools/perf/perf stat -a -e cycles,instructions,cache-misses,cache-references,uncore_imc_0/cas_count_read/,uncore_imc_0/cas_count_write/,power/energy-cores/,power/energy-pkg/,power/energy-ram/ make -j4 2> gcc_papi.perf.$i 1> gcc_papi.stdio.$i ; echo $i; make clean ; done
