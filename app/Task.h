#ifndef __Task_H
#define __Task_H

#include <stdint.h>

//#include "LinkedList.h"

//Task Control Block
typedef enum{
  RUNNING,
  READY,
  SPAWNED,
  TERMINATED,
  BLOCKING,
  SLEEPING,
}TaskState;

typedef struct{
    TaskState state;
    uint32_t stack;
}Tcb;

#endif //__Task_H
