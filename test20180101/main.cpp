#include <stdio.h>
#define LEN 11


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#define SERVPORT 3333
#define MAXDATASIZE 100

int main22(int argc,char *argv[]) {
    int sockfd,sendbytes;
    char buf[MAXDATASIZE];
    struct hostent* host;
    struct sockaddr_in serv_addr;

    if((host = gethostbyname("172.30.84.48")) == NULL) {//转换为hostent
        //perror("gethostbyname");
        exit(1);
    }

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {//创建socket
        //perror("socket");
        exit(1);
    }

    //填充数据
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    bzero(&(serv_addr.sin_zero),8);

    if((connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))) == -1) {//发起对服务器的链接
        //perror("connect");
        exit(1);
    }

    if((sendbytes = send(sockfd,"hello.",5,0)) == -1) {//发送消息给服务器端
        //perror("send");
        exit(1);
    }

    close(sockfd);

}
















/*
 * 幻方生成器 n x n 方格的每行、每列、每条对角线上的和都相等
 */


int mainCubic(void)
{
    int h[LEN][LEN] = {0},i,x,y;
    int o_x,o_y;

    x = LEN / 2;
    y = 0;
    h[x][y] = 1; //[中间列,0行]初始化1
    for(i=2;i <= LEN * LEN;i++){
        o_x = x;
        o_y = y;

        y--; //向上移动一行
        if(y < 0){
            //如果 y 越界
            y = LEN + y;
        }

        x++; //向右移动一列
        if( x >= LEN){
            //如果 x 越界
            x = x - LEN;
        }

        if(h[x][y] != 0){
            //如果要移动的位置已经被占用
            x = o_x;
            y = o_y + 1;  //放到前一个数的正下方
            if(y >= LEN){
                y = y - LEN;
            }
        }
        h[x][y] = i;
    }

    //打印输出，注意， 按行(y)输出
    for(y=0;y<LEN;y++){
        for(x=0;x<LEN;x++){ //一列列输出
            printf("%4d",h[x][y]);
        }
        printf("\n");
    }
}