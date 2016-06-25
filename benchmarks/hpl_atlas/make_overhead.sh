#!/bin/sh
for i in `seq 1 10`; do /home/vince/research/linux-kernel/linux-4.1.5/tools/perf/perf stat -a -e cycles,instructions,cache-misses,cache-references,uncore_imc/data_reads/,uncore_imc/data_writes/,power/energy-cores/,power/energy-pkg/,power/energy-ram/ mpirun.mpich -np 4 ./xhpl 2> hpl_atlas.perf.$i 1> hpl_atlas.stdio.$i ; echo $i; done
