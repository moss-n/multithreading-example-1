#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char * HELLO_MESSAGE; 
int THREADS_CREATED = 0; 

void * workerThreadFunc(void * tid){
  while(THREADS_CREATED == 0){
     
  }
  HELLO_MESSAGE = "HELLO WORLD!";
}

void * workerThreadFunc2(void * tid){
    while(THREADS_CREATED == 0){
    
  }
  for(int i = 0; i < 13; i++){
      printf("\n%c \n",HELLO_MESSAGE[i]); 
  }
}

int main(){

  pthread_t tid0;
  pthread_t tid1; 

  pthread_create(&tid0,NULL,workerThreadFunc,(void *)&tid0);
  pthread_create(&tid1,NULL,workerThreadFunc2,(void *)&tid1);
  sleep(1);
  THREADS_CREATED = 1; 

  pthread_exit(NULL);
  return 0;

}