#include "shdmemsendtask.h"
#include"param.h"

ShdMemSendTask::ShdMemSendTask()
{

}

int ShdMemSendTask::send(QString message) {
    char*  buffer;
    QByteArray ba = message.toLatin1();
    buffer=ba.data();
    return sendShdMem(buffer);
}


int ShdMemSendTask::init(){
    return initShdMem(Param::Shdkey);
}
