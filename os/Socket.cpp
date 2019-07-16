//
// Created by hjw on 7/1/19.
//
#include "Socket.h"
sockaddr_in servaddr,client_sockaddr;


//标识符
int sock_cli,client_sockfd;
int BUFFER_SIZE= 4096;
char *recvbuf;

int initSocket(int type,int port,const char*ip){
    recvbuf=new char[BUFFER_SIZE];
    memset(recvbuf, 0, sizeof(recvbuf));
    sock_cli = socket(AF_INET,SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);  ///Server port
    servaddr.sin_addr.s_addr = inet_addr(ip);  ///Server ip
    if(type==0){
        connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr));
    }else{
        socklen_t client_len= sizeof(client_sockaddr);
        socklen_t server_len=sizeof(servaddr);
        int bret=bind(sock_cli, (struct sockaddr*)&servaddr, server_len);
        int lret=listen(sock_cli, 5);
        client_sockfd = accept(sock_cli, (struct sockaddr*)&client_sockaddr, &client_len);
    }
    return 0;
}



int sendSocket(const char *message){
    int ret=send( sock_cli, message, BUFFER_SIZE,0);
    return ret;
}

int recvSocket(char *resvMsg){
    auto r=(int)recv(client_sockfd, resvMsg, BUFFER_SIZE,0);
}

