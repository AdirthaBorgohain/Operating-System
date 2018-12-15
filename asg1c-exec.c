#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int status, f = fork();
	if(f == 0) {
		printf("Inside Child Process: \n");
		char *args[] = {"./execDemo", NULL};		//A NULL terminated array of pointers
		// Compile execDemo.c before proceeding: gcc execDemo.c -o execDemo
		int i = execv(args[0],args);
		if(i == -1) {
			printf("execv process failed. Please execute \"gcc execDemo.c -o execDemo\" before proceeding\n");
			exit(1);
		}
	} else if(f > 0) {
		wait(&status);
		if(WIFEXITED(status)) { 			//Check whether child process executed successfully
			printf("***Child process executed successfully***\n");
		}
		else {
			printf("Child process execution failed.\n");
			exit(1);
		}
		printf("Inside Parent Process: \n");
	} else {
		printf("Fork process failed.\n");
		exit(1);
	}
	return 0;
}

