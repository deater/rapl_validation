all:	haswell_ep.png haswell_i7.png

haswell_ep.png:	haswell_ep.eps
	convert -density 300 haswell_ep.eps -resize 640x640 haswell_ep.png

haswell_ep.eps:	haswell_ep.jgr
	jgraph < haswell_ep.jgr > haswell_ep.eps



haswell_i7.png:	haswell_i7.eps
	convert -density 300 haswell_i7.eps -resize 640x640 haswell_i7.png

haswell_i7.eps:	haswell_i7.jgr
	jgraph < haswell_i7.jgr > haswell_i7.eps


clean:	
	rm *.eps

