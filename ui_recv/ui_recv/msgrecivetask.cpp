#include "msgrecivetask.h"
#include"param.h"

MsgReciveTask::MsgReciveTask()
{

}



int MsgReciveTask::recv(){
    char buffer[MAX_MSG_SIZE];
    int ret=recvMsg(buffer);
    recvData=QString(buffer);
    return ret;
}

int MsgReciveTask::init(){
    return initMsg(Param::mqkey);
}

