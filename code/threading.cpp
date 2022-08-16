#include <iostream>
#include <pthread.h>
#include <semaphore.h>

pthread_t thread_1;
pthread_t thread_2;
sem_t simple_semaphore;

//take away the need for using "std::"
using namespace std;

void mutex(){
  //main thread waits both
  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
}

void run_semaphore(){
  //initialize a semaphore with value = 1 (one running) and allows 1
  /* address: pointed by sem.
     pshared = 0 thread shares a process
     this sem has initial value of 1 (one running thread)
  */
  int success;
  success = sem_init(&simple_semaphore, 0, 1)+1;

  cout << (success?"Success running semaphore!":"Something went wrong with it");
}

void* mutex_sum(void *p){
  sem_wait(&simple_semaphore);
  cout << 1+2;
  cout << "\n";
  sem_post(&simple_semaphore);
}

void* mutex_subtract(void *p){
  sem_wait(&simple_semaphore);
  cout << 90-2-1;
  cout << "\n";
  sem_post(&simple_semaphore);
}

int main(){
  /* Initilize both threads that were created*/
  pthread_create(&thread_1, NULL, mutex_sum, NULL);
  pthread_create(&thread_1, NULL, mutex_subtract, NULL);

  /* alternatives */
  run_semaphore();
  //mutex();

  return 0;
}
