
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int GLOBAL = 0;

typedef struct {

  int easyID;
  pthread_t * tid;

}ThreadArgs;

void *workerThreadFunc(void *arg)
{
    while (GLOBAL == 0){

    }
    ThreadArgs * arg_p = (ThreadArgs *) arg;
    long *tid = (long *) arg_p->tid;
    int  easyID = (int ) arg_p->easyID;
    static int shared_var = 0;
    int local_var = 0;
    while (shared_var < 10){
      sleep(1); //remove to see behavior where single thread increments up to ten
      shared_var++;

      printf("ThreadID: %d, shared_var: %d\n",easyID, shared_var);
    }
    printf("Global Var Value: %d, Static Var Value: %d, Local Var Value: %d, Thread ID: %ld, easyID: %d \n",
    GLOBAL, shared_var, ++local_var, *tid, easyID);
}

int main()
{

    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t *pthreads[] = {&tid0,&tid1,&tid2};


    for (int i = 0; i < 3; i++) {
       ThreadArgs *args = (ThreadArgs *) malloc(sizeof(ThreadArgs));
       args->tid = pthreads[i];
       args->easyID = i;
	     pthread_create(args->tid, NULL, workerThreadFunc, (void *)args);

        };
        sleep(1);
        GLOBAL = 1;

    pthread_exit(NULL);
    return 0;
}
