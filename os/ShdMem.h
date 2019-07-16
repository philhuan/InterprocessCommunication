//
// Created by hjw on 7/1/19.
//

#ifndef TEST_SEND_SHDMEM_H
#define TEST_SEND_SHDMEM_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define MEN_SIZE 2048

struct SharedMsg
{
    int written;//非0：表示可读，0表示可写
    char text[MEN_SIZE];
};

int initShdMem(int key = 7602);
int sendShdMem(const char *message);
int recvShdMem(char *resvMsg);

extern  struct SharedMsg *shared;

#endif //TEST_SEND_SHDMEM_H
