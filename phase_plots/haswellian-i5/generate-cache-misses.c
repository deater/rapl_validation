#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_time;
	double current_misses;

	double time_offset=-1.005;

	int header=0,line=0,i;

	line=0;

	while(1) {

		/* read cache-misses */

		/* skip cycles */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		/* skip instructions */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		/* get cache misses */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		if (header==0) {
			printf("(* %s *)\n","Cache Misses");
			header=1;
		}

		current_time=atof(time);
		current_misses=atof(value);

		printf("%lf\t%lf",current_time+time_offset,current_misses);
		printf("\n");

		line++;

		/* Skip to next */
		for(i=0;i<6;i++) {

			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}

	}

	return 0;
}
