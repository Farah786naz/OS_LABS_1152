#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

     if (pid == 0) {
        
        execlp("top", "top", NULL);
        
        // If execlp returns, it failed
        perror("execlp failed");
    } else{
       
        wait(NULL); 
        printf("Child process finished");
    }
    
    return 0;
}