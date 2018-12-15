#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void call_function(void)
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
		while(1)
			sleep(1);
	} else if(f < 0){
		printf("Fork process failed\n");
		exit(1);
	}
	exit(0);
}

void handle_signal()
{
	call_function();					//user defined function is being called
}

int main(void)
{
	//signal(SIGINT, handle_signal);
	if(signal(SIGINT, handle_signal) == SIG_ERR)		//System interrupt being called
		printf("\n Could not catch SIGINT\n");
	while(1)
		sleep(1);
	return(0);
}
