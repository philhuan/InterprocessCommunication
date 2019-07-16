//
// Created by hjw on 6/30/19.
//

#ifndef TEST_SEND_MSG_H
#define TEST_SEND_MSG_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 512
#define MSG_TYPE 1

struct Msg
{
    long type;
    char text[MAX_MSG_SIZE];
};

int initMsg(int key = 7602);

int sendMsg(const char *message);

int recvMsg(char *resvMsg);

extern int msgid;








#endif //TEST_SEND_MSG_H
