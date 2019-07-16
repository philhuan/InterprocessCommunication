#ifndef MSGRECIVETASK_H
#define MSGRECIVETASK_H
#include"task.h"
#include"Msg.h"

class MsgReciveTask : public Task
{
public:
    MsgReciveTask();
    int recv();
    int init();
};

#endif // MSGRECIVETASK_H
