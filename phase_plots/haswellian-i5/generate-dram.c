#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *ch1;

	double current_time=-1.0,timestep=1.0/2048.0;
	double voltage,current,power;
	double time_offset=-1.0;

	int line=0;
	int i;

	if (argc>1) {
		time_offset=atof(argv[1]);
	}


	printf("(* Measured DRAM *)\n");


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

		printf("%lf %lf\n",current_time+time_offset,power);

		current_time+=timestep;
		line++;
	}

	printf("(* Done Measured DRAM *)\n");


	return 0;
}
