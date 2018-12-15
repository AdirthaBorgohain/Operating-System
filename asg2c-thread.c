#include <stdio.h>
#include <pthread.h>

void *thFunc(void* arg) {
	printf("HELLO WORLD\n");
}

int main(){
	printf("Generating user thread ID\n");
	pthread_t thID;
	pthread_create(&thID,NULL,thFunc,NULL);
	printf("After joining thread to the process\n");
	pthread_join(thID,NULL);
	return 0;
}
