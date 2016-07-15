#!/bin/sh

echo "Sleep results"
echo
echo "Measured Package"
../energy-from-plot 700 20594 < haswellian_sleep.jgr
echo "RAPL Package"
../energy-from-plot 20602 20700 < haswellian_sleep.jgr
echo "Measured DRAM"
../energy-from-plot 21117 41012 < haswellian_sleep.jgr
echo "RAPL DRAM"
../energy-from-plot 41021 41119 < haswellian_sleep.jgr
