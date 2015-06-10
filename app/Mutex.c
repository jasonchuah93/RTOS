#include <stdint.h>
#include "Mutex.h"
#include "Scheduler.h" //use for task switch

void mutexInit(Mutex *mutex){
  mutex->owner = NULL;
}

void mutexAcquire(Mutex *mutex){
  mutex->owner->state = BLOCKING;
  if(mutex->owner == NULL){
    mutex->ownder = runningTcb;
  }else{
    
  }
}

void mutexRelease(Mutex *mutex){
  mutex->owner->state = BLOCKING;
  if(mutex->owner == NULL){
    mutex->ownder = runningTcb;
  }else{
    
  }
}

