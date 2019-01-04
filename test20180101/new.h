//
// Created by lugt on 2018/3/10.
//

#ifndef TEST20180101_NEW_H
#define TEST20180101_NEW_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <memory.h>

#define SERVPORT 3333//定义端口号
#define BACKLOG 10//请求队列中允许的最大请求数
#define MAXDATASIZE 5//数据长度

int mai23n() {
    struct sockaddr_in server_sockaddr,client_sockaddr;//声明服务器和客户端的socket存储结构
    int sin_size,recvbytes;
    int sockfd,client_fd;//socket描述符
    char buf[MAXDATASIZE];//传输的数据

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {//建立socket链接
        perror("Socket");
        exit(1);
    }

    printf("Socket success!,sockfd=%d\n",sockfd);

    //以sockaddt_in结构体填充socket信息
    server_sockaddr.sin_family = AF_INET;//IPv4
    server_sockaddr.sin_port = htons(SERVPORT);//端口
    server_sockaddr.sin_addr.s_addr = INADDR_ANY;//本主机的任意IP都可以使用
    memset(&(server_sockaddr.sin_zero),0,8);//填充0

    if((bind(sockfd,(struct sockaddr *)&server_sockaddr,sizeof(struct sockaddr))) == -1) {//bind函数绑定
        perror("bind");
        exit(-1);
    }

    printf("bind success!\n");

    if(listen(sockfd,BACKLOG) == -1) {//监听
        perror("listen");
        exit(1);
    }

    printf("listening ... \n");

    if((client_fd = accept(sockfd,(struct sockaddr *) &client_sockaddr,&sin_size)) == -1) {//等待客户端链接
        perror("accept");
        exit(1);
    }

    printf("accept success!\n");

    if((recvbytes = recv(client_fd,buf,MAXDATASIZE,0)) == -1) {//接收客户端的请求
        perror("recv");
        exit(1);
    }

    printf("received a connection : %s\n",buf);
    close(sockfd);

}

#endif //TEST20180101_NEW_H
