
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int GLOBAL = 0; 
  
void *workerThreadFunc(void *arg) 
{ 

    while ( GLOBAL < 10){
    	GLOBAL++; 
    	}; 

    long *tid = (long *) arg;
    static int shared_var = 0; 
    int local_var = 0; 

    printf("Global Var Value: %d, Static Var Value: %d, Local Var Value: %d, Thread ID: %ld, \n", 
    ++GLOBAL, ++shared_var, ++local_var, *tid); 
} 
  
int main() 
{ 
    
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2; 
    pthread_t *pthreads[] = {&tid0,&tid1,&tid2};


    for (int i = 0; i < 3; i++) {
    
	pthread_create(pthreads[i], NULL, workerThreadFunc, (void *)pthreads[i]); 
        
        }; 
  
    pthread_exit(NULL); 
    return 0; 
} 


