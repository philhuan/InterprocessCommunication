#include "msgsendtask.h"
#include"param.h"
MsgSendTask::MsgSendTask()
{

}

int MsgSendTask::send(QString message) {
    char*  buffer;
    QByteArray ba = message.toLatin1();
    buffer=ba.data();
    return sendMsg(buffer);
}


int MsgSendTask::init(){
    return initMsg(Param::mqkey);
}
