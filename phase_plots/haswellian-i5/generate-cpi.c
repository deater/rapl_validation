#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_time;
	double current_cycles;
	double current_insn;

	double time_offset=-1.005;

	int header=0,line=0,i;

	line=0;

	while(1) {

		/* read cycles */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		if (header==0) {
			printf("(* %s *)\n","CPI");
			header=1;
		}

		current_time=atof(time);
		current_cycles=atof(value);


		/* read cycles */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		current_insn=atof(value);





		printf("%lf\t%lf",current_time+time_offset,current_cycles/current_insn);
		printf("\t(* %f/%f *)",current_cycles,current_insn);
		printf("\n");

		line++;

		/* Skip to next */
		for(i=0;i<7;i++) {
			/* read cycles */
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}

	}

	return 0;
}
