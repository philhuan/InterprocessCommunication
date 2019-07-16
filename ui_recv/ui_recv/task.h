#ifndef TASK_H
#define TASK_H
#include<QString>


class Task
{
public:
    Task();
    QString getData();
    virtual int recv()=0;
    virtual int init()=0;

protected:
    QString recvData;

};

#endif // TASK_H
