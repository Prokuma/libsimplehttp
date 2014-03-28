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