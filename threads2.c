#include <stdio.h>
#include <pthread.h>   // For POSIX threads
#include <stdlib.h>    // For exit()


void* threadFunction(void* arg) {
    int* thread_num = (int*) arg;   
    printf("Thread %d is running\n", *thread_num);
    free(thread_num);   
    pthread_exit(NULL); 
}

int main() {
    pthread_t threads[3];   
    int i, result;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        int* thread_num = (int*) malloc(sizeof(int));   
        *thread_num = i + 1;    
        result = pthread_create(&threads[i], NULL, threadFunction, thread_num);

        if (result) {
            printf("Error creating thread %d\n", i + 1);
            exit(EXIT_FAILURE); 
        }
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);   
    }

    printf("All threads have finished.\n");
    return 0;
}
