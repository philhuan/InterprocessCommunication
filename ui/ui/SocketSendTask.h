#ifndef SOCKETSENDTASK_H
#define SOCKETSENDTASK_H
#include"Socket.h"
#include"task.h"

class SocketSendTask : public Task
{
public:
    SocketSendTask();
    int init();
    int send(QString message);
private:
    bool inited;
};

#endif // SOCKETSENDTASK_H
