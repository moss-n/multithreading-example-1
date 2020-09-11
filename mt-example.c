#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * workerThreadFunc(void * tid){
  long * myID = (long *) tid;
  printf("HELLO WORLD! THIS IS THREAD %ld\n",*myID);

};

int main()
{

  pthread_t tid0;
  pthread_t tid1;
  pthread_t tid2;
  pthread_t * pthreads[] = {&tid0,&tid1,&tid2};

  for (int i = 0; i < 3; i++){

      pthread_create(pthreads[i],NULL,workerThreadFunc,
        (void *) pthreads[i]);
  }


  pthread_exit(NULL);
  return 0;
}
