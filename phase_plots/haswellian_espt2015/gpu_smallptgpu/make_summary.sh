#!/bin/sh

echo "OpenCL raytrace"
echo
echo "Measured Package"
../energy-from-plot 1038 54573 < haswellian_gpu_smallpt.jgr
echo "RAPL Package"
../energy-from-plot 57502 57763 < haswellian_gpu_smallpt.jgr
echo "Measured DRAM"
../energy-from-plot 58179 111714 < haswellian_gpu_smallpt.jgr
echo "RAPL DRAM"
../energy-from-plot 114107 114368 < haswellian_gpu_smallpt.jgr
