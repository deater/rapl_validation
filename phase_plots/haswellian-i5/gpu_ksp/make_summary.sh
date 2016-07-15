#!/bin/sh

echo "OpenGL KSP"
echo
echo "Measured Package"
../energy-from-plot 1252 55940 < haswellian_gpu_ksp.jgr
echo "RAPL Package"
../energy-from-plot 56493 56760 < haswellian_gpu_ksp.jgr
echo "Measured DRAM"
../energy-from-plot 57383 111902 < haswellian_gpu_ksp.jgr
echo "RAPL DRAM"
../energy-from-plot 112080 112346 < haswellian_gpu_ksp.jgr
