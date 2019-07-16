//
// Created by hjw on 7/1/19.
//

#ifndef TEST_SEND_PIPE_H
#define TEST_SEND_PIPE_H

#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#include <zconf.h>
#include <sys/stat.h>
#include <string.h>

int initPipe(int open_mode=O_WRONLY,const char *fifo_name= "/tmp/hjw_pipe");
int sendPipe(const char *message);
int recvPipe(char *resvMsg);
int closePipe();


#endif //TEST_SEND_PIPE_H
