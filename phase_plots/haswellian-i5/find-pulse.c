#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *ch1,*ch2,*ch3,*ch4;

	double current_time=0.0,timestep=1.0/2048.0;

	double voltage,last_voltage=-5;

	while(1) {

		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;
		ch1=strtok(result,",");
		ch2=strtok(NULL,",");
		ch3=strtok(NULL,",");
		ch4=strtok(NULL,",");


		voltage=atof(ch4);

		if ( ((voltage<0) && (last_voltage>0)) ||
			((voltage>0) && (last_voltage<0))) {
			printf("%lf\n",current_time);
		}

		current_time+=timestep;

		last_voltage=voltage;

		(void)ch1;
		(void)ch2;
		(void)ch3;

	}

	return 0;
}
