#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *ch1,*ch2,*ch3;

	double current_time=-1.0,timestep=1.0/2048.0;
	double voltage1,voltage2,current1,current2,power;

	double time_offset=-1.0;

	if (argc>1) {
		time_offset=atof(argv[1]);
	}

	printf("(* Measured CPU *)\n");

	while(1) {

		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;
		ch1=strtok(result,",");
		ch2=strtok(NULL,",");
		ch3=strtok(NULL,",");

		voltage1=atof(ch2);
		voltage2=atof(ch3);

		current1=(voltage1-0.5)/0.133;
		current2=(voltage1-0.5)/0.133;

		power=(current1+current2)*12;

		printf("%lf %lf (* %lf %lf *)\n",current_time+time_offset,power,
			voltage1,voltage2);

		current_time+=timestep;
	}

	printf("(* Done Measured CPU *)\n");

	(void)ch1;

	return 0;
}
