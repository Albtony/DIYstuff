#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>


// pipe 2 exec commands
int pipeExecOut(char *cmdArgs1[], char *cmdArgs2[]){
	size_t first_id;
	size_t second_id;
	char res[100];
	int result = -1;
	int pipefd1[2];
	int pipefd2[2];

	pipe(pipefd1);
	first_id = fork();

	if (first_id < 0) _Exit(EXIT_FAILURE);
	if (first_id == 0) {
		dup2(pipefd1[1], STDOUT_FILENO);
		close(pipefd1[0]);
		execv(cmdArgs1[0], &cmdArgs1[1]);
	}
	else {
		dup2(pipefd1[0], STDIN_FILENO);
		close(pipefd1[1]);

		pipe(pipefd2);
		second_id = fork();
		if (second_id < 0) _Exit(EXIT_FAILURE);
		if (second_id == 0) {
			dup2(pipefd2[1], STDOUT_FILENO);
            close(pipefd2[0]); 
			execv(cmdArgs2[0], &cmdArgs2[1]);
		} else {
			while(wait(NULL) > 0);
			read(pipefd2[0], res, sizeof(res));
			result = atoi(res);
		}
	}

	return result;
}

// count files at dir with pipeExecOut
int countFile(char *dir){
	char *lsArgs[] = {"/usr/bin/ls", "ls", dir, NULL};
	char *wcArgs[] = {"/usr/bin/wc", "wc", "-l", NULL};
	return pipeExecOut(lsArgs, wcArgs);
}

int main (){
	printf("file count : %d\n", countFile("."));
	return EXIT_SUCCESS;
}