# Operating-System
This repo consists of the solutions for the assignments of Operating System course offered by our university.

Assignments:

1.      a. Write a C program to create a child process using the system call fork( ) and from the child process, display the PID and PPID and also display the same from parent process. Demonstarte the use of exit(0) and exit(1).

        b. Write a C program like the assignment 1(a). But here use the system call wait() system to synchronize the execution of parent program in your program until child process finishes.

        c. Write a C program like the assignment 1(b). and overlay a user degined program into the address space of the child process using execv() system call.Again use wait() system call to synchronize the execution of parent program in your program until child process finishes.Here use the macro WIFEXITED to capture the returned status of the child in parent process. Also demonstarte the use of argument vector to print the program name by the child process.

2.      a. Write a C program by using signal() system call to handle the reception of SIGINT signal by executing a particular(user) function, which function is responsible for creating a child process by using fork( ) system call and then you have to display the PROCESS ID and PARENT PROCESS ID from the parent process as well as from the child process.

        b. Write a C program which will take the Process ID and signal ID as input to demonstrate the use of kill( ) system call.

        c. Write a C program to create a user level thread using system call pthread_create( ) and assign the thread to display the “HELLO WORLD” . Use pthread_exit() in your program (if possible) for terminating the thread. 
        
3.      a. Write a C program to handle the reception of INTERRUPT FROM THE KEYBOARD signal by executing a particular (user) function, which function is responsible for creating a child process by using fork() system call. Also, the child process will take an input N (N is the no. of terms to generate the Fibonacci series) from the user and generate the Fibonacci series up to N terms. Then the child process will send the Fibonacci series terms one by one to the parent process by using pipe() system call and the parent process will read the Fibonacci series terms one by one and will display it. 

4.      a. Write a C program which will be able to read a file using read() system call. Now you provide a mechanism to set a lock by using fcntl() system call and to release the lock by using the same fcntl() system call. For setting up and releasing out a lock, you have to fill up a structure flock (struct flock) with proper values. Now you run the program from two different terminals simultaneously and demonstrate that if one process has got the lock, then that process only can read the file. But the other one is not permitted to read the file until the lock is released by the first process. That means, only one process who acquires the lock can read the file at any instant of time. 

5.      b. Write a C programs using socket programming approach to implement a multithreaded echo-server and a client program to demonstrate client-server communication.

6.      a. Write two C programs named program1.c and program2.c to demonstrate the concept of shared memory where program1 (process1) will be responsible for writing it’s process id and program2 (process2) will be responsible for reading the contents whatever program1(process1) writes. Moreover try to remove the shared memory segment that is created for your above mentioned operations properly by using proper system call. 

        b. Write a C program to get the process submission time & termination time of a process. For this assignment your C program will create a child process and writes the submission and termination time of the child process into a file.
        
7.      a. Write two C program named program1.c and program2.c and both will be responsible for reading the contents of a single file. Now you put the concept of semaphore to provide synchronization between the process program1 and program2, so that program2 can read the contents of the specified file only after reading the contents of the file by program1. Again if the program1 runs for n times, then program2 can read the contents of the file at most n times only, not more than that. Moreover you have to remove the semaphore that is created for your above mentioned operations properly by using proper system call. 
