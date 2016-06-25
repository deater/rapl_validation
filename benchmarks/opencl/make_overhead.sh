#!/bin/sh
#for i in `seq 1 10`; do /home/vince/research/linux-kernel/linux-4.1.5/tools/perf/perf stat -a -e cycles,instructions,cache-misses,cache-references,uncore_imc/data_reads/,uncore_imc/data_writes/,power/energy-cores/,power/energy-pkg/,power/energy-ram/ ./smallptgpu 2> opencl.perf.$i 1> opencl.stdio.$i ; echo $i; done

# uncore broken on 4.0.5???
for i in `seq 1 10`; do /home/vince/research/linux-kernel/linux-4.1.5/tools/perf/perf stat -a -e cycles,instructions,cache-misses,cache-references,power/energy-cores/,power/energy-pkg/,power/energy-ram/ ./smallptgpu 2> opencl.perf.$i 1> opencl.stdio.$i ; echo $i; done
