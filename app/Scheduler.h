#ifndef Scheduler_H
#define Scheduler_H

#include "Task.h"

extern Tcb *runningTcb;

void taskSwitch();

#endif // Scheduler_H
