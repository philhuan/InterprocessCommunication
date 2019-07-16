#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QMutex>
#include"task.h"
#include"head.h"

#include "QThread"

class MyThread : public QThread
{
private:
    Task* task;
    QMutex* mutex;
    bool full;
    QString data;
    bool finished;

public:
    MyThread(QMutex* mutex,Task*task);
    void run();
    QString getData();
    bool isFull();
    bool quit();


};

#endif // MYTHREAD_H
