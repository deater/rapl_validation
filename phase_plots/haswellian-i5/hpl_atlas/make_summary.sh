#!/bin/sh

echo "HPL Atlas"
echo
echo "Measured Package"
../energy-from-plot 1726 127087 < haswellian_hpl_atlas.jgr
echo "RAPL Package"
../energy-from-plot 130411 131023 < haswellian_hpl_atlas.jgr
echo "Measured DRAM"
../energy-from-plot 131443 256750 < haswellian_hpl_atlas.jgr
echo "RAPL DRAM"
../energy-from-plot 260073 260685 < haswellian_hpl_atlas.jgr
