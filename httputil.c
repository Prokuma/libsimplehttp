#include "httputil.h"

char* IpToDomain(char* domain){
    struct hostent *hptr;
    char **aptr;
    int i = 0;

    hptr = gethostbyname(domain);
    if(hptr == NULL){
        printf("ERROR!\n");
    }

    return inet_ntoa(*(struct in_addr*)hptr->h_addr_list[i]);
}

char** HTTPHeaderCut(char* response){
    int i = 0;
    char* p;
    char** dp;

    p = strtok(response,"\r\n\r\n");
    while(NULL != p){
	dp[i] = p;
        p = strtok(NULL, "\r\n\r\n");
	i++;
    }

    return dp;
}
