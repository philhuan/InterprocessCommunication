#include "SocketRecvTask.h"
#include"Socket.h"
#include"param.h"

SocketRecvTask::SocketRecvTask()
{

}

int SocketRecvTask::recv(){
    if(!inited){
        init();
    }
    char buffer[4096];
    int ret=recvSocket(buffer);
    recvData=QString(buffer);
    if(ret==-1||recvData.length()==0){
        recvData="端口被占用";
    }
    return ret;
}

int SocketRecvTask::init(){
    inited=true;
    char*  buffer;
    QByteArray ba = Param::ip.toLatin1();
    buffer=ba.data();
    return initSocket(1,Param::port,buffer);
}
