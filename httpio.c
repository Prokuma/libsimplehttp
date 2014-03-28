#include "httpio.h"

int client_process_http(int sockfd, char* host, char* page, char* params, char* type, char* response){
    char sendline[MAXLINE + 1], recvline[MAXLINE + 1];
    ssize_t  n;
    snprintf(sendline, MAXSUB,
    "%s %s HTTP/1.0\r\n"
            "Host: %s\r\n"
            "Content-type: application/x-www-form-urlencoded\r\n"
            "Content-length: %d\r\n"
            "User-Agent: libhttp/0.1"
            "%s", type ,page, host, (int)strlen(params), params);
    write(sockfd, sendline, strlen(sendline));

    int offset = 0;
    while((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        strcpy(response+offset, recvline);
        offset += n;
    }
    return offset;
}

void client_send(char* type,char* address,char* params, char* response, char* page){
    int sockfd;
    struct sockaddr_in servaddr;
    char str[50];

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr.s_addr = inet_addr(address);
    inet_pton(AF_INET,str, &servaddr.sin_addr);

    connect(sockfd,(SA *)&servaddr, sizeof(servaddr));
    client_process_http(sockfd, address, page, params, type, response);
    close(sockfd);
}

int server_bind(char* address,int port,char* response,int response_size){
    int sockfd,x,xx,sockfd2;
    struct sockaddr_in servaddr,cliaddr;
    //char str[1000];

    sockfd = socket(AF_INET, SOCK_STREAM,0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(address);
    //inet_pton(AF_INET, str, &servaddr.sin_addr);
    x = bind(sockfd, (SA *)&servaddr, sizeof(servaddr));
    if(x < 0){
        puts("Bind Error!");
    }
    listen(sockfd, 5);
    xx = sizeof(cliaddr);
    sockfd2 = accept(sockfd, (SA *)&cliaddr, &xx);
    read(sockfd2,response, response_size);
    return sockfd2;
}

void server_send(char* content, int sockfd){
    write(sockfd,content, strlen(content));
    close(sockfd);
}