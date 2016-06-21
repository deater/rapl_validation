#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	int first_line=299;
	int last_line=20594;
	int line=0;

	double first_time=-20.0,last_time=0.0;
	double previous_time=-20.0;

	double current_time=0.0,current_power;
	double total_energy=0;

	int i;

	if (argc>1) {
		first_line=atoi(argv[1]);
	}
	if (argc>2) {
		last_line=atoi(argv[2]);
	}


	/* Skip to next */
	for(i=0;i<first_line;i++) {
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;
		line++;
	}

	while(1) {

		/* read package energy */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		if (line==last_line) break;

		time=strtok(result," \t");

		if (time==NULL) {
			printf("Error at line %d\n",line);
			break;
		}

		value=strtok(NULL," \t");

		if (value==NULL) {
			printf("Error at line %d\n",line);
			break;
		}

//		printf("%s %s %lf\n",time,value,total_energy);

		current_time=atof(time);
		current_power=atof(value);

		if (first_time==-20.0) {
			first_time=current_time;
		}
		else {
			total_energy+=current_power*(current_time-previous_time);
		}
		previous_time=current_time;

		line++;
	}

	last_time=current_time;

	printf("\tFirst time %lf Last time %lf Diff %lf\n",
		first_time,last_time,last_time-first_time);
	printf("\tTotal Energy=%lf\n",total_energy);
	printf("\tAverage Power=%lf\n",
		total_energy/(last_time-first_time));

	return 0;
}
