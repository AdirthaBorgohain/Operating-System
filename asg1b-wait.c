#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int f = fork();
	if(f == 0){
		printf("Inside Child Process:\n");
		printf("PID is: %d\n",getpid());
		printf("PPID is: %d\n\n",getppid());
	} else if(f > 0){
		wait(NULL);
		printf("Inside Parent Process:\n");
		printf("PID is: %d\n",getpid());
		printf("PPID is: %d\n\n",getppid());
	} else if(f < 0){
		printf("Fork process failed\n");
		exit(1);
	}
	exit(0);
}

