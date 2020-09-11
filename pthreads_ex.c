
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

enum arithematic_operations{ADDITION,DIVISION,MULTIPLICATION}; 

int GLOBAL = 0; 

typedef struct {

enum arithematic_operations operation; 

pthread_t *tid; 

}ThreadArgs;
  


  
void *workerThreadFunc(void *args) 
{ 

    while ( GLOBAL < 10){
    	GLOBAL++; 
    	}; 

    ThreadArgs * args_struct = (ThreadArgs *)args; 
    long *tid = (long *) args_struct->tid;
    static int shared_var = 0; 
    
    printf("%d - OPERATION\n", args_struct->operation);
    if(args_struct->operation == ADDITION){
    	printf("ADDITION! - Thread ID %ld \n", *tid);
    	++shared_var; 
    	}; 
    if(args_struct->operation == DIVISION){

    	printf("DIVISION! - Thread ID %ld \n", *tid);
       shared_var = shared_var * shared_var; 
       shared_var = shared_var / 2; 
       }
    if(args_struct->operation == MULTIPLICATION) {
    	printf("MULTIPLICATION! - Thread ID %ld \n", *tid); 
    	shared_var * 10; 
    	}; 

    printf("Global Var Value: %d, Static Var Value: %d, Thread ID: %ld, \n", 
    ++GLOBAL, ++shared_var, *tid); 
} 
  
int main() 
{ 
    
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2; 
    pthread_t *pthreads[] = {&tid0,&tid1,&tid2};


    for (int i = 0; i < 3; i++) {
    
    	ThreadArgs * args = (ThreadArgs *) malloc(sizeof(ThreadArgs)); 
	args->tid = pthreads[i]; 
	args->operation = i; 
	//pthread_create(pthreads[i], NULL, workerThreadFunc, (void *)pthreads[i]); 
        pthread_create(args->tid, NULL, workerThreadFunc, (void *)args); 
        
        }; 
  
    pthread_exit(NULL); 
    return 0; 
} 


