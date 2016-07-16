#include <stdio.h>

int main(int argc, char **argv) {

	char string[BUFSIZ];
	char *result;
	double t,j,last_time=0.0;

	while(1) {

		result=fgets(string,BUFSIZ,stdin);
		if (result==NULL) break;

		sscanf(string,"%lf,%lf,",&t,&j);

		result=fgets(string,BUFSIZ,stdin);
		if (result==NULL) break;

		printf("%lf\t%lf\n",t,j/(t-last_time));

		last_time=t;
	}

	return 0;
}
