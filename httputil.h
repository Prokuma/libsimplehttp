/**
* HTTP관련한 유틸 함수들을 모아놓은 헤더
* 도메인에서 ip로 바꾸어 주는 함수
* 헤더를 파싱하는 함수등 다양하다
*/
#ifndef HTTPUTIL_H_
#define HTTPUTIL_H_

#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* IpToDomain(char* domain);
char** HTTPHeaderCut(char* response);

#endif
