

 #include <stdio.h>
 #include <pthread.h>

 typedef struct {
 char* name;
 float cgpa;
 } Student;

int deanlist =0;
pthread_mutex_t mutex;

 void* printData(void* arg) {
    Student* data = (Student*)arg;
    printf("My name is %s and my cgpa is: %f\n", data->name, data->cgpa);
    if(data->cgpa >= 3.5){
        pthread_mutex_lock(&mutex);
        deanlist++;
        pthread_mutex_unlock(&mutex);
        printf("The student %s make to the Dean's list.\n",data->name);
    }
    else{
        printf("The student %s didnt make to the Dean's list.\n",data->name);
    }
    return NULL;
 }
 int main() {
    pthread_t t1, t2,t3;
    Student data1 = {"Farah", 3.53};
    Student data2 = { "Fatima", 3.2};
    Student data3 = { "Eman", 3.2};
    pthread_create(&t1, NULL, printData, &data1);
    pthread_create(&t2, NULL, printData, &data2);
    pthread_create(&t3, NULL, printData, &data3);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t2, NULL);

    printf("The total number of students on the Dean's List:%d \n",deanlist);
    printf("All threads done.\n");
    return 0;
 }