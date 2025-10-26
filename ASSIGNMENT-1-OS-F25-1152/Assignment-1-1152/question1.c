//THREAD CREATION
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_fuction(void* arg){
    int thread_number=*(int*)arg;
    printf("The thread number is %d\n",thread_number);
    sleep(2);
    printf("Thread %d has been completed\n",thread_number);
}

int main(){
    pthread_t thread[5];
    int num[5];

    for(int i=0;i<5;i++){
        num[i]=i+1;
        pthread_create(&thread[i],NULL,thread_fuction,&num[i]);
        
    }
   
    for(int i=0;i<5;i++){
        pthread_join(thread[i],NULL);
    }
    printf("All threads completed\n");
    
}