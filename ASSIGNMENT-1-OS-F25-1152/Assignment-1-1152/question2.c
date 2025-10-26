#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Thread function - this will run in the new thread
void* thread_function(void* arg) {

    printf("Hello Farah! Welcome to the world of threads..\n");
    return NULL;
}
int main() {
    pthread_t thread_id;
    printf("Waiting for the greeting...\n");
    // Create a new thread
    pthread_create(&thread_id, NULL, thread_function, NULL);

    pthread_join(thread_id, NULL);
    printf("Greeting completed...\n");
    return 0;
}
