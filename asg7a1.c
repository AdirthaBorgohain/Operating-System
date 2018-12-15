    #include <stdio.h> 
    #include <stdlib.h> 
    #include <errno.h> 
    #include <sys/types.h> 
    #include <sys/ipc.h> 
    #include <sys/sem.h> 
    int main(void) 
    { 
        key_t key; 
        int semid; 
        char c;
        struct sembuf sb = {0, -1, 0};  
        if ((key = ftok("adirtha.txt", 'J')) == -1) { 
            perror("ftok"); 
            exit(1); 
        } 
 
        if ((semid = semget(key, 1, 0)) == -1) { 
            perror("semget"); 
            exit(1); 
        } 
        printf("Press return to lock: "); 
        getchar(); 
        printf("Trying to lock...\n"); 
        if (semop(semid, &sb, 1) == -1) { 
            perror("semop"); 
            exit(1); 
        } 
        printf("Locked.\n");  
        printf("Ready to access file. \n");
        FILE *fp;
        fp = fopen("adirtha.txt","r");
        printf("The contents of the file: \n\n");
        c = fgetc(fp); 
        while (c != EOF) 
        { 
            printf ("%c", c); 
            c = fgetc(fp); 
        } 
        printf("\n\nFile reading ended. \n");
        fclose(fp); 
        printf("Press return to unlock: "); 
        getchar(); 
        sb.sem_op = 1;  
        if (semop(semid, &sb, 1) == -1) { 
            perror("semop"); 
            exit(1); 
        } 
        printf("Unlocked\n"); 
        return 0; 
    } 
