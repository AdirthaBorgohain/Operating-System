/* Write a C program to create a child process using the system
call fork( ) and from the child process, display the PID and PPID and
also display the same from parent process. Demonstrate the use of
exit(0) and exit(1). */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
        int f = fork();
        if(f == 0){
                printf("Inside Child Process:\n");
                printf("PID is: %d\n",getpid());
                printf("PPID is: %d\n\n",getppid());
        } else if(f > 0){
                printf("Inside Parent Process:\n");
                printf("PID is: %d\n",getpid());
                printf("PPID is: %d\n\n",getppid());
        } else if(f < 0){
                printf("Fork process failed\n");
                exit(1);
        }
        exit(0);
}

