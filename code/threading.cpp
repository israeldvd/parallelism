#include <iostream>
#include <p.thread>
#include <semaphore.h>

pthread_t thread_1;
pthread_t thread_2;
pthread_t thread_3;
sem_t simple_semaphore;

using namespace std; //takes away the need for using "std::"

void mutex(){
  //main thread waits both
  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
}

void run_semaphore(){
  sem_init()
}

int main(){

  return 0;
}
