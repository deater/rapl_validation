#!/bin/sh

echo "HPL mkl"
echo
echo "Measured Package"
../energy-from-plot 1026 53217 < haswellian_hpl_mkl.jgr
echo "RAPL Package"
../energy-from-plot 53889 54145 < haswellian_hpl_mkl.jgr
echo "Measured DRAM"
../energy-from-plot 54563 106751 < haswellian_hpl_mkl.jgr
echo "RAPL DRAM"
../energy-from-plot 107426 107682 < haswellian_hpl_mkl.jgr
