//pass mixed

 #include <stdio.h>
 #include <pthread.h>

 typedef struct {
 char* name;
 float cgpa;
 } ThreadData;

 void* printData(void* arg) {
 ThreadData* data = (ThreadData*)arg;
 printf("My name is %s and my cgpa is: %f\n", data->name, data->cgpa);
 return NULL;
 }
 int main() {
 pthread_t t1, t2;
 ThreadData data1 = {"Farah", 3.53};
 ThreadData data2 = { "Fatima", 3.2};
 pthread_create(&t1, NULL, printData, &data1);
 pthread_create(&t2, NULL, printData, &data2);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 printf("All threads done.\n");
 return 0;
 }