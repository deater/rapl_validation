#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *ch1;

//	double current_time=0.0,
	double timestep=1.0/2048.0;
	double voltage,current,power,energy;
	double total_energy=0.0;

	int line=0;
	int i;


	/* skip to one we want */
	for(i=0;i<line;i++) {
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;
	}

	line=0;

	while(1) {

		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;
		ch1=strtok(result,",");
//		ch2=strtok(NULL,",");

		voltage=atof(ch1);

		voltage=voltage/303;

		current=voltage/0.0033;	/* 3.3mOhm resistor */
		power=current*1.517;
		energy=power*timestep;

//		printf("%lf %lf\n",current_time,power);

		total_energy+=energy;

		line++;
	}

	printf("Total DAQ energy %lf\n",total_energy);

	return 0;
}
