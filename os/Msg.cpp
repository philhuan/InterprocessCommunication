//
// Created by hjw on 6/30/19.
//
#include "Msg.h"

int msgid;
struct Msg msg;


/**
 * 初始化消息队列
 * @param key
 * @return 返回0表示成功
 */
int initMsg(int key) {
    msg.type=1;
    //通过key分辨不同的消息队列
    msgid = msgget((key_t) key, 0666 | IPC_CREAT);
    return msgid == -1;
}

/**
 * 发送消息,以"\n"结尾否则直到遇到下一个"\n"才一起发送
 * @param message 消息内容
 * @return 返回0表示成功
 */
int sendMsg(const char *message) {
    strcpy(msg.text,message);
    int result = msgsnd(msgid, (void *) &msg, MAX_MSG_SIZE, IPC_NOWAIT) == -1;
    return result == -1;
}

/**
 * 接收消息
 * @param resvMsg
 * @return 返回0表示成功
 */
int recvMsg(char* resvMsg){
    int result = msgrcv(msgid,(void*)&msg,MAX_MSG_SIZE,0,0);
    strcpy(resvMsg,msg.text);
    return result==-1;
}



