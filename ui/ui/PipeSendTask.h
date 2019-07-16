#ifndef PIPESENDTASK_H
#define PIPESENDTASK_H
#include"task.h"

class PipeSendTask:public Task
{
public:
    PipeSendTask();
    int init();
    int send(QString message);

private:
    bool inited=false;
};

#endif // PIPESENDTASK_H
