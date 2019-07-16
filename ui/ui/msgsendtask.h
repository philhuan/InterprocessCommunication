#ifndef MSGSENDTASK_H
#define MSGSENDTASK_H
#include"Msg.h"
#include"head.h"
#include"task.h"

class MsgSendTask:public Task
{
public:
    MsgSendTask();
    int init();
    int send(QString message);
};

#endif // MSGSENDTASK_H
