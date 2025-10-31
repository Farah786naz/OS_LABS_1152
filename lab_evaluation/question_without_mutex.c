#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
 int counter = 0; 
//DEIFNE A CRITICAL SECTION THAT WILL INCREMENT THE COUNTER
int critical_section(int process){
    if (process==0){                     //HERE RACE CONDITION CAN BE SEEN BEACUSE EACH THREAD WILL  TRY
        for(int i=0;i<=10000;i++){       //TO INCCREMENT THE COUNTER AS THEIR CONDITION IS MET.
            counter++;
        }
    }
    else if (process==1){
        for(int i=0;i<=10000;i++){
            counter++;
        }
    }
    else{
        for(int i=0;i<=10000;i++){
            counter++;
        }
    }
}

//THREAD FUNCTIONS WILL Execute the crirical section for each thread
void* process0(void* arg){
    printf("process0 started\n");
    critical_section(0);  //INREMENT THE COUNTER FOR PROCESS 0
    printf("process0 ended\n");
}
void* process1(void* arg){
    printf("process1 started\n");
    critical_section(1); //INREMENT THE COUNTER FOR PROCESS 1
    printf("process1 ended\n");
}
void* process2(void* arg){
    printf("process2 started\n");
    critical_section(2);  //INREMENT THE COUNTER FOR PROCESS 2
    printf("process2 ended\n");
}



 int main() {
    pthread_t t1, t2,t3;
    int num1=0;
    int num2=1;
    int num3=2;
    pthread_create(&t1, NULL, process0, &num1); //CREATE PROCESS 0
    pthread_create(&t2, NULL, process1, &num2); //CREATE PROCESS 1
    pthread_create(&t3, NULL, process2, &num3); //CREATE PROCESS 2
    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("value:%d\n",counter);   //PRINT THE COUNTER

 }