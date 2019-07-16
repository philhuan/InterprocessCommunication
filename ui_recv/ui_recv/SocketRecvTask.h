#ifndef SOCKETRECVTASK_H
#define SOCKETRECVTASK_H
#include"head.h"
#include"task.h"

class SocketRecvTask:public Task
{
public:
    SocketRecvTask();
    int recv();
    int init();
private:
    bool inited=false;
};

#endif // SOCKETRECVTASK_H
