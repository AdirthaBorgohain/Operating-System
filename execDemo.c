#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *prog_name = argv[0];
	prog_name += 2;
        printf("I am a program called by the exec system call and my program name is \"%s\"\n",prog_name);
        exit(0);
}
