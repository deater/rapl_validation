#/bin/sh
sleep 1
echo start
/home/vince/git/papers/2015_cohpc_rapl/tools/toggle_rts /dev/ttyUSB0 5000
/home/vince/research/power-measurement/power_benchmarks/stream-5.10/stream_omp
/home/vince/git/papers/2015_cohpc_rapl/tools/toggle_rts /dev/ttyUSB0 5000
echo stop
sleep 1

