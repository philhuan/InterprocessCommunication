//
// Created by hjw on 7/1/19.
//
#include "ShdMem.h"

struct SharedMsg *shared = NULL;
int shmid;


int initShdMem(int key){

    shmid = shmget((key_t)key, sizeof(struct SharedMsg), 0666|IPC_CREAT);
    if(shmid == -1)
    {
        return 1;
    }

    void *shm = shmat(shmid, (void*)0, 0);
    if(shm==(void*)-1){
        return 2;
    }
    shared = (struct SharedMsg*)shm;
    shared->written = 0;
    return 0;
}

int sendShdMem(const char *message) {
    strcpy(shared->text, message);
    shared->written = 1;
    return 0;
}


int recvShdMem(char *resvMsg){
    while (shared->written ==0){
        usleep(250000);
    }
    strcpy(resvMsg,shared->text);
    shared->written = 0;
}