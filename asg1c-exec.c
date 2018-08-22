/* Write a C program like the assignment 1(b). and overlay a user designed program into the address space of the child process using execv() system call.Again use wait() system call to synchronize the execution of parent program in your program until child process finishes.Here use the macro WIFEXITED to capture the returned status of the child in parent process. Also demonstrate the use of argument vector to print the program name by the child process. */

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
			printf("execv process failed\n");
			exit(1);
		}
	} else if(f > 0) {
		wait(&status);
		// check for error during execution of child process
		if(WIFEXITED(status)) {				
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


