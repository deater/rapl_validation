#include <stdio.h>
#include <string.h>

double get_joules(char *base, int which, double *get_seconds) {

	FILE *fff;
	char filename[BUFSIZ];
	char line[BUFSIZ];
	char *result;
	double joules=-1.0;
	double seconds;

	sprintf(filename,"%s.%d",base,which);
	fff=fopen(filename,"r");
	if (fff==NULL) {
		fprintf(stderr,"ERROR!\n");
		return -1.0;
	}

	while(1) {
		result=fgets(line,BUFSIZ,fff);
		if (result==NULL) break;
		if (strstr(line,"power/energy-ram/")) {
			sscanf(line,"%lf",&joules);
			printf("Trace %d %lfJ, ",which,joules);
		}
		if (strstr(line,"seconds time elapsed")) {
			sscanf(line,"%lf",&seconds);
			printf("%lf seconds, %lfW\n",
			seconds,joules/seconds);
		}

	}
	fclose(fff);
	*get_seconds=seconds;
	return joules;
}

int main(int argc, char **argv) {

	int i;
	int count=10;
	double joules,total_joules=0.0,total_seconds=0.0,seconds;

	if (argc<2) {
		printf("Usage: %s base count\n",argv[0]);
	}

	for(i=1;i<=10;i++) {
		joules=get_joules(argv[1],i,&seconds);
		total_joules+=joules;
		total_seconds+=seconds;
	}

	printf("RAPL average Joules=%lf\tRAPL average Watts=%lf\n",total_joules/(double)count,total_joules/total_seconds);

	return 0;
}
