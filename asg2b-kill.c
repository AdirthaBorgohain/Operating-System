#include <stdio.h>
#include <sys/signal.h>

int main() {
        int i,k;
        printf("Enter PID: ");
        scanf("%d", &i);
        k = kill(i,SIGKILL);
        if(k == 0)
                printf("Process killed successfully\n");
        else
                printf("Killing process failed\n");
        return(0);
}
