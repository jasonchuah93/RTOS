#ifndef __Mutex_H
#define __Mutex_H

#include <stdint.h>
#include "Task.h"
#include "LinkedList.h"

//Task Control Block
typedef struct{
    Tcb *owner;
    int counter;
    LinkedList *blockTcb;
}Mutex;

void mutexInit(Mutex *mutex);
void mutexAcquire(Mutex *mutex);
void mutexRelease(Mutex *mutex);

#endif // Mutex_H
