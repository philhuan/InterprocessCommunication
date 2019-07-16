#ifndef SHDMEMSENDTASK_H
#define SHDMEMSENDTASK_H
#include"ShdMem.h"
#include"head.h"
#include"task.h"

class ShdMemSendTask:public Task
{
public:
    ShdMemSendTask();
    int init();
    int send(QString message);
};

#endif // SHDMEMSENDTASK_H
