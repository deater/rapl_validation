#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *ch1,*ch2;

	double current_time=-0.5,last_time=0,timestep=1.0/2048.0;
	double current_value,last_value;
	double voltage,current,power;

	int line=0;
	int i;
	int channel;

	if (argc>1) {
		channel=atoi(argv[1]);
	}

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
		ch2=strtok(NULL,",");

		voltage=atof(ch1);

		voltage=-voltage; /* wire connected backwards */

		current=voltage/0.0033;	/* 3.3mOhm resistor */
		power=current*1.5;

		printf("%lf %lf\n",current_time,power);

		current_time+=timestep;
		line++;
	}

	return 0;
}
