#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;
	char *units;
	char *event;

	int header=0,line=0;
	int skip=7;

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

			printf("%s\t%s",time,value);
			if (strlen(units)>0) {
				printf("\t(* %s *)",units);
			}
			printf("\n");

		}
		line++;
	}

	return 0;
}
