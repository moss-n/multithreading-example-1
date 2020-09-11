#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * workerThreadFunc(void * tid){
  long * myID = (long *) tid;
  printf("HELLO WORLD! THIS IS THREAD %ld\n",*myID);
}

int main(){

  pthread_t tid0;

  pthread_create(&tid0,NULL,workerThreadFunc,(void *)&tid0);

  pthread_exit(NULL);
  return 0;

}
