#ifndef SHDMEMSENDTASK_H
#define SHDMEMSENDTASK_H
#include"task.h"


class ShdMemSendTask:public Task
{
public:
    ShdMemSendTask();
    int recv();
    int init();

};

#endif // SHDMEMSENDTASK_H
