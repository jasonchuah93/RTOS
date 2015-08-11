#ifndef __Semaphore_H
#define __Semaphore_H

#include "LinkedList.h"

typedef struct{
    int counter;
    int size;
    LinkedList *blockedTcb;
}Semaphore;

void semaphoreDown(Semaphore *sem, int count);
void semaphoreUp(Semaphore *sem, int count);

#endif // Semaphore_H
