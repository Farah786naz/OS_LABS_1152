#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
pthread_mutex_t mutex;  //Declare the mutex
int counter=0;
int critical_section(int process){
    if (process==0){
        pthread_mutex_lock(&mutex);  //LOCK THE MUTEX HERE SO THAT IF A PROCESS START OTHER WILL WAIT
        for(int i=0;i<1000;i++){
            counter++;
        }
        pthread_mutex_unlock(&mutex);  //UNLOCK THE MUTEX
    }
    else if (process==1){
        pthread_mutex_lock(&mutex); //LOCK THE MUTEX HERE SO THAT IF A PROCESS START OTHER WILL WAIT
        for(int i=0;i<1000;i++){
            counter++;
        }
        pthread_mutex_unlock(&mutex); //UNLOCK THE MUTEX
    }
    else{
        pthread_mutex_lock(&mutex); //LOCK THE MUTEX HERE SO THAT IF A PROCESS START OTHER WILL WAIT
        for(int i=0;i<1000;i++){
            counter++;
        }
        pthread_mutex_unlock(&mutex); //UNLOCK THE MUTEX
    }
}



//PROCESS 0 FUNCTION
void* process0(void* arg){
    printf("process0 started\n");
    critical_section(0);
    printf("process0 ended\n");
}

//PROCESS 1 FUNCTION
void* process1(void* arg){
    printf("process1 started\n");
    critical_section(1);
    printf("process1 ended\n");
}

//PROCESS 2 FUNCTION
void* process2(void* arg){
    printf("process2 started\n");
    critical_section(2);
    printf("process2 ended\n");
}

int main(){
    pthread_mutex_init(&mutex,NULL);
    pthread_t t1,t2,t3;
    
    
    
    pthread_create(&t1,NULL,process0,NULL);  //Create thread 0
    pthread_create(&t2,NULL,process1,NULL);  //Create thread 1
    pthread_create(&t3,NULL,process2,NULL);  //Create thread 2

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    printf("The final counter variable is: %d",counter);

    pthread_mutex_destroy(&mutex);  //DESTROY THE MUTEX HERE

}