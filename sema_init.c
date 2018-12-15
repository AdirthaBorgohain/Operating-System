#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  
#include <string.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/sem.h> 
    int main(void){

        union semun {
       int              val;    /* Value for SETVAL */
       struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
       struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                   (Linux-specific) */
   } arg;
        key_t key; 
        int semid; 
        //union semun arg; 
        if ((key = ftok("adirtha.txt", 'J')) == -1) { 
            perror("ftok"); 
            exit(1); 
        } 
        /* create a semaphore set with 1 semaphore: */ 
        if ((semid = semget(key, 1, 0666 | IPC_CREAT)) == -1) { 
            perror("semget"); 
            exit(1); 
        } 
        /* initialize semaphore #0 to 1: */ 
        arg.val = 1; 
        if (semctl(semid, 0, SETVAL, arg) == -1) { 
            perror("semctl"); 
            exit(1); 
        } 
        return 0; 
    } 
