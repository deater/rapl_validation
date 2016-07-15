#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_time,last_time=0;
	double package_energy;

	double time_offset=-1.005;

	int header=0,line=0,i;

	line=0;

	while(1) {

		/* Skip to next */
		for(i=0;i<7;i++) {
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}

		/* read package energy */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		if (header==0) {
			printf("(* %s *)\n","Package Power");
			header=1;
		}

		current_time=atof(time);
		package_energy=atof(value);

		printf("%lf\t%lf",current_time+time_offset,
			package_energy/(current_time-last_time));
		printf("\t(* Watts, %lf Joules *)\n",package_energy);

		last_time=current_time;

		line++;

		/* Skip to next */
		for(i=0;i<1;i++) {
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}


	}

	return 0;
}
