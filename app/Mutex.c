#include <stdio.h>
#include <stdint.h>
#include "Mutex.h"
#include "Scheduler.h" //use for task switch

void mutexInit(Mutex *mutex){
  //TODO : disable interrupt
  mutex->owner = NULL;
  //mutex->queue = LinkedListCreate();
  //TODO : re-enable interrupt
}

void mutexAcquire(Mutex *mutex){
  //TODO : disable interrupt
  mutex->owner->state = BLOCKING;
  if(mutex->owner == NULL){
    mutex->owner = runningTcb;
    //TODO : re-enable interrupt
  }else{
    mutex->owner->state = BLOCKING;
    //TODO : put the current owner to blocking queue
    //TODO : task switch with the help of the scheduler
   
  }
  //No need to re-
}

void mutexRelease(Mutex *mutex){
  
}

