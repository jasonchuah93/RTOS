#ifndef __Mutex_H
#define __Mutex_H

#include <stdint.h>
#include "Task.h"
//#include "LinkedList.h"

//Task Control Block
typedef struct{
    TaskState state;
    uint32_t stack;
}
#endif // Mutex_H
