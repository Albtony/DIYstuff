#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

// function to pick random files at dir -> needs to know how many file in dir
char* pickRandomFiles(char *dir, int fileCount){
	struct dirent *entry;
    DIR *dp;
	srand(time(NULL));

	// int fileCount = countFile(dir) - 2; -> fileCount from external function
	int randomNum = rand() % fileCount;
	
	int count = 0;
    dp = opendir(dir);
    if (dp != NULL) 
		while ((entry = readdir(dp))){
			if(strcmp(".", entry -> d_name) == 0 || strcmp("..", entry -> d_name) == 0) {
				entry = readdir(dp);
				continue;
			}

			if(count == randomNum) break;
			count++;
		}
    closedir(dp);

	return entry -> d_name;
}

int main () {
	printf("file: %s\n", pickRandomFiles(".", 2));  	// 2 -> allFiles - 1 (itself)
	return EXIT_SUCCESS;
}