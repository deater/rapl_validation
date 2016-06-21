#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int use_watts=1;

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;
	char *units;
	char *event;

	double current_time,last_time=0;
	double current_value,last_value;

	int header=0,line=0;
	int skip=5;
	int i;

	if (argc>1) {
		line=atoi(argv[1]);
	}

	if (argc>2) {
		skip=atoi(argv[2]);
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

		if (line%skip==0) {

			time=strtok(result,",");
			value=strtok(NULL,",");
			units=strtok(NULL,",");
			event=strtok(NULL,",\n");

			if (header==0) {
				printf("(* %s *)\n",event);
				header=1;
			}

			current_time=atof(time);
			current_value=atof(value);

			/* Raw */
			if (!use_watts) {
				printf("%lf\t%lf",current_time,current_value);
				if (strlen(units)>0) {
					printf("\t(* %s *)",units);
				}
			}

			/* Watts */
			else {
				printf("%lf\t%lf",current_time,
					current_value/(current_time-last_time));
				printf("\t(* Watts *)");
			}

			printf("\n");
			last_time=current_time;
			last_value=current_value;

		}
		line++;
	}

	return 0;
}
