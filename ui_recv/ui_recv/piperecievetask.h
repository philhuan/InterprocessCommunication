#ifndef PIPERECIEVETASK_H
#define PIPERECIEVETASK_H
#include"task.h"

class PipeRecieveTask : public Task
{
public:
    PipeRecieveTask();
    int recv();
    int init();
private:
    bool inited=false;
};

#endif // PIPERECIEVETASK_H
