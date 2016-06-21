#!/bin/sh

echo "HPL Openblas"
echo
echo "Measured Package"
../energy-from-plot 1252 75251 < haswellian_hpl_openblas.jgr
echo "RAPL Package"
../energy-from-plot 76633 76995 < haswellian_hpl_openblas.jgr
echo "Measured DRAM"
../energy-from-plot 77413 151411 < haswellian_hpl_openblas.jgr
echo "RAPL DRAM"
../energy-from-plot 152794 153156 < haswellian_hpl_openblas.jgr
