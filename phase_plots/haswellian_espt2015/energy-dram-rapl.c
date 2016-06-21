#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buffer[BUFSIZ];
	char *result;
	char *time;
	char *value;

	double current_time;
	double dram_energy;
	double total_energy=0;

	int i;

	while(1) {

		/* Skip to next */
		for(i=0;i<8;i++) {
			result=fgets(buffer,BUFSIZ,stdin);
			if (result==NULL) break;
		}

		/* read package energy */
		result=fgets(buffer,BUFSIZ,stdin);
		if (result==NULL) break;

		time=strtok(result,",");
		value=strtok(NULL,",");

		current_time=atof(time);
		dram_energy=atof(value);

		total_energy+=dram_energy;
		(void)time;
		(void)current_time;
	}

	printf("Total DRAM energy=%lf\n",total_energy);

	return 0;
}
