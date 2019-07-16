#include "ShdMemSendTask.h"
#include"ShdMem.h"
#include"param.h"
ShdMemSendTask::ShdMemSendTask()
{

}

int ShdMemSendTask::recv(){
    char buffer[MEN_SIZE];
    int ret=recvShdMem(buffer);
    recvData=QString(buffer);
    return ret;
}

int ShdMemSendTask::init(){
    return initShdMem(Param::Shdkey);
}

