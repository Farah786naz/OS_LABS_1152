#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* comp_factorial(void* arg) {

    int num = *(int*)arg; // Cast void* back to int*
    int* factorial= malloc(sizeof(int));
    *factorial=1;
    for(int i=num;i>0;i--){
        *factorial*=i;
    }
    return (void*)factorial;
}
int main() {
    pthread_t thread_id;
    int number = 3;
    void* factorial;
    printf("The number given is: %d\n", number);
    pthread_create(&thread_id, NULL, comp_factorial, &number);
    pthread_join(thread_id, &factorial);
    printf("The factorial that we received is: %d\n",*(int*)factorial);
    printf("Main thread done.\n");
    return 0;
}