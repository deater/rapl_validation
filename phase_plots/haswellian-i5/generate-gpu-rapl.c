#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_time,last_time=0;
	double dram_energy;

	double time_offset=-1.005;

	int line=0,i;

	line=0;

	printf("(* %s *)\n","GPU RAPL Power");

	while(1) {

		/* Skip to next */
		for(i=0;i<5;i++) {
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}

		/* read package energy */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");


		current_time=atof(time);
		dram_energy=atof(value);

		printf("%lf\t%lf",current_time+time_offset,
			dram_energy/(current_time-last_time));
		printf("\t(* Watts, %lf Joules *)\n",dram_energy);

		last_time=current_time;

		line++;

		/* Skip to next */
		for(i=0;i<3;i++) {
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}


	}

	return 0;
}
