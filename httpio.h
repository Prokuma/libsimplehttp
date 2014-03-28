/*
 * 실질적인 기능을 구현하는 소켓부분
 * Client용과 Server용 함수가 존재한다
 */

#ifndef HTTPIO_H_
#define HTTPIO_H_

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define SA      struct sockaddr
#define MAXLINE 4096
#define MAXSUB  200
extern int h_errno;

void DieWithError(char *errorMessage);

int client_process_http(int sockfd, char* host, char* page, char* params, char* type, char* response);

void client_send(char* type,char* address,char* params, char* response, char* page);

int server_bind(char* address,int port,char* response,int response_size);

void server_send(char* content, int sockfd);


#endif /* HTTPIO_H_ */