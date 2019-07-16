#include "SocketSendTask.h"
#include"head.h"
#include"param.h"

SocketSendTask::SocketSendTask()
{

}


int SocketSendTask::send(QString message) {
    if(!inited){
        init();
    }
    char*  buffer;
    QByteArray ba = message.toLatin1();
    buffer=ba.data();
    return sendSocket(buffer);
}


int SocketSendTask::init(){
    inited=true;
    inited=true;
    char*  buffer;
    QByteArray ba = Param::ip.toLatin1();
    buffer=ba.data();
    return initSocket(0,Param::port,buffer);
}
