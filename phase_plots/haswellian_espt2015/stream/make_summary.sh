#!/bin/sh

echo "STREAM results"
echo
echo "Measured Package"
../energy-from-plot 761 26850 < haswellian_stream.jgr
echo "RAPL Package"
../energy-from-plot 26989 27117 < haswellian_stream.jgr
echo "Measured DRAM"
../energy-from-plot 27536 53627 < haswellian_stream.jgr
echo "RAPL DRAM"
../energy-from-plot 53767 53895 < haswellian_stream.jgr
