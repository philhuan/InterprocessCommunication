#include "mythread.h"
#include "QDebug"
#include "stdlib.h"
//#include <unistd.h>

MyThread::MyThread(QMutex* mutex,Task *task):
    task(task),mutex(mutex),full(false),finished(false)
{

}

void MyThread::run(){

    while (!finished) {
        qDebug()<<"thread start";
        mutex->lock();
        bool _full=full;
        mutex->unlock();

        if(!_full){
            task->recv();
            mutex->lock();
            data=task->getData();
            full=true;
            mutex->unlock();

        }
        sleep(1);
        qDebug()<<"thread run";

    }
}

QString MyThread::getData(){
    if(full){
        full=false;
        return task->getData();
    }
    return QString();
}

bool MyThread::isFull(){
    return full;
}

bool MyThread::quit(){
    QThread::quit();
    finished=true;
    return true;
}
