#include "piperecievetask.h"
#include"Pipe.h"
#include"param.h"

PipeRecieveTask::PipeRecieveTask()
{

}

int PipeRecieveTask::recv(){
    if(!inited){
        init();
    }
    char buffer[4096];
    int ret=recvPipe(buffer);
    recvData=QString(buffer);
    return ret;
}

int PipeRecieveTask::init(){
    inited=true;
    char*  buffer;
    QByteArray ba = Param::pipname.toLatin1();
    buffer=ba.data();
    return initPipe(O_RDONLY,buffer);
}
