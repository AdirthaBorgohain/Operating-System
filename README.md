# Operating-System
This repo consists of the solutions for the assignments of Operating System course offered by our university.

Assignments:

1.      a. Write a C program to create a child process using the system call fork( ) and from the child process, display the PID and PPID and also display the same from parent process. Demonstarte the use of exit(0) and exit(1).

        b. Write a C program like the assignment 1(a). But here use the system call wait() system to synchronize the execution of parent program in your program until child process finishes.

        c. Write a C program like the assignment 1(b). and overlay a user degined program into the address space of the child process using execv() system call.Again use wait() system call to synchronize the execution of parent program in your program until child process finishes.Here use the macro WIFEXITED to capture the returned status of the child in parent process. Also demonstarte the use of argument vector to print the program name by the child process.

2.      a. Write a C program by using signal() system call to handle the reception of SIGINT signal by executing a particular(user) function, which function is responsible for creating a child process by using fork( ) system call and then you have to display the PROCESS ID and PARENT PROCESS ID from the parent process as well as from the child process.

        b. Write a C program which will take the Process ID and signal ID as input to demonstrate the use of kill( ) system call.

        c. Write a C program to create a user level thread using system call pthread_create( ) and assign the thread to display the “HELLO WORLD” . Use pthread_exit() in your program (if possible) for terminating the thread. 