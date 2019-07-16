#include "PipeSendTask.h"
#include"Pipe.h"
#include"param.h"

PipeSendTask::PipeSendTask()
{

}


int PipeSendTask::send(QString message) {
    if(!inited){
        init();
    }
    char*  buffer;
    QByteArray ba = message.toLatin1();
    buffer=ba.data();
    return sendPipe(buffer);
}


int PipeSendTask::init(){
    inited=true;
    char*  buffer;
    QByteArray ba = Param::pipname.toLatin1();
    buffer=ba.data();
    return initPipe(O_WRONLY,buffer);
}
