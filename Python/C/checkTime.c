#include <time.h>
#include <stdlib.h>
#include <stdio.h>


// function to now vs threshold
int checkTime(char *threshold){
	double diff;
	char buffer[26];
	struct tm *tmNow, tmThreshold;
	time_t timeNow, timeThreshold;

	strptime(threshold, "%F %T", &tmThreshold);

	timeNow = time(0);
	tmNow = localtime(&timeNow);
	timeNow = mktime(tmNow);

	timeThreshold = mktime(&tmThreshold);

	diff = difftime(timeThreshold, timeNow);
	if(diff >= 0) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}

int main (){
	char *time = "2022-12-22 04:44:00";

	if(checkTime(time)) printf("its past %s\n", time);
	else printf("its before %s\n", time);
	return EXIT_SUCCESS;
}