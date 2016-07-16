#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define STATE_NONE	0
#define STATE_DTR_START	1
#define STATE_DTR_STOP	2
#define STATE_IN_TRACE	3

int main(int argc, char **argv) {

	int i,result,done=0;
	int fd,temp_int,rate,channels;
	float points[8];
	int ticks=0;
	double watts_vdd,watts_vpp;
	long long temp64;
	int trace=0;
	int threshold=1;
	double total_joules_vdd=0.0;
	double total_joules_vpp=0.0;
	double total_time=0.0;
	double gain_vdd=100.0;
	double resistor_vdd=0.005;
	double gain_vpp=300.0;
	double resistor_vpp=0.005;
	double start_time=1.0,end_time=5.0;
	double time_elapsed=0.0;

	if (argc<3) {
		fprintf(stderr,"Error! need two args!\n");
	}

	start_time=atof(argv[1]);
	end_time=atof(argv[2]);

	/* stdin */
	fd=0;

	read(fd,&temp_int,4);
	printf("(* Version %d *)\n",temp_int);

	read(fd,&temp64,8);
	printf("(* Start Time %lld.",temp64);
	read(fd,&temp64,8);
	printf("%06lld *)\n",temp64);

	read(fd,&temp_int,4);
	rate=temp_int;
	printf("(* Rate %d Hz *)\n",rate);

	printf("(* Gain VDD %lf *)\n",gain_vdd);
	printf("(* Resistor VDD %lf *)\n",resistor_vdd);
	printf("(* Gain VPP %lf *)\n",gain_vpp);
	printf("(* Resistor VPP %lf *)\n",resistor_vpp);

	threshold=rate/500;
	if (threshold<1) threshold=1;

	read(fd,&temp_int,4);
	channels=temp_int;
	printf("(* Channels %d *)\n",channels);

	while(!done) {

		for(i=0;i<channels;i++) {

			result=read(fd,&points[i],sizeof(float));

			if (isinf(points[i])) {
				done=1;
				break;
			}

			if (result<sizeof(float)) {
				done=1;
				break;
			}

//			printf("%lf\t",points[i]);

		}

		if (done) break;

		watts_vdd=((points[0]/gain_vdd)/resistor_vdd)*points[1];
		watts_vpp=((points[2]/gain_vpp)/resistor_vpp)*2.5;

		time_elapsed=(double)ticks/(double)rate;

		if ((time_elapsed>start_time) && (time_elapsed<end_time)) {

			if (0) {
				printf("%lf\t%lf\n",
					time_elapsed-start_time-1.0,
					watts_vdd);
			}
			else {
				printf("%lf\t%lf\n",
					time_elapsed-start_time-1.0,
					watts_vpp);
			}
		}
		ticks++;
	}

	read(fd,&temp64,8);
	printf("(* Stop Time %lld.",temp64);
	read(fd,&temp64,8);
	printf("%06lld *)\n",temp64);

	printf("(* Average Joules=%lf\tAverage Watts=%lf *)\n",(total_joules_vdd+total_joules_vpp)/(double)trace,(total_joules_vdd+total_joules_vpp)/total_time);

	return 0;
}
