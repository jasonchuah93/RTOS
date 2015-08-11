#ifndef __MailBox_H
#define __MailBox_H

#include "Mutex.h"
#include "Semaphore.h"

typedef struct{
    int *buffer;
    int size;
    Semaphore slotsAvailable;
    Semaphore slotsUsed;
    int writeIndex;
    int readIndex;
    Mutex mutexForBuffer;
}MailBox;

void mailBoxInit(MailBox *mailbox, int size);
void mailBoxSendMessage(MailBox *mailbox, int message);
int mailBoxGetMessage(MailBox *mailbox);

#endif // MailBox_H
