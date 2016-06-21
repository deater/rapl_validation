#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_watts;

	int header=0,line=0;

	line=0;

	double current_time=0,time_offset=-1.0;

	if (argc>1) {
		time_offset=atof(argv[1]);
	}

	while(1) {

		/* read Power */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		if (header==0) {
			printf("(* %s *)\n","Watts Up Pro Watts");
			header=1;
		}

		current_watts=atof(value);

		current_time=(double)line;

		printf("%lf\t%lf",current_time+time_offset,current_watts);
		printf("\t(* %s *)","Watts");
		printf("\n");

		line++;

	}


	(void) time;

	return 0;
}
