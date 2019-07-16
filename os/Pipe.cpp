//
// Created by hjw on 7/1/19.
//
#include "Pipe.h"

int pipe_fd = -1;

int initPipe(int open_mode,const char *fifo_name ){


    if(access(fifo_name,F_OK)==-1)
    {
        if(mkfifo(fifo_name,0777)!=0)
        {
            return 1;
        }
    }

    pipe_fd = open(fifo_name,open_mode);

    if(pipe_fd==-1){
        return 2;
    }

    return 0;
}


int sendPipe(const char *message){
    return write(pipe_fd, message, strlen(message));
}


int recvPipe(char *resvMsg){
    int res=read(pipe_fd,resvMsg,PIPE_BUF);
    return res;
}

int closePipe(){
    close(pipe_fd);
}