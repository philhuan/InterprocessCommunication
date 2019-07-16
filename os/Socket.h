//
// Created by hjw on 7/1/19.
//

#ifndef TEST_SEND_SOCKET_H
#define TEST_SEND_SOCKET_H
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <zconf.h>

int initSocket(int type,int port,const char*ip="127.0.0.1");

int sendSocket(const char *message);

int recvSocket(char *resvMsg);



#endif //TEST_SEND_SOCKET_H
