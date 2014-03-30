#include "httputil.h"

char* IpToDomain(char* domain){
    struct hostent *hptr;

    hptr = gethostbyname(domain);
    if(hptr == NULL){
        printf("ERROR!\n");
    }

    return inet_ntoa(*(struct in_addr*)hptr->h_addr_list[0]);
}

char* getHTTPContent(char* response){
    char* re;

    re = strstr(response, "\r\n\r\n");
    re += 4;
    return re;
}

char* getHTTPHeader(char* response){
    char *re, *re2;

    re = response;
    re2 = strstr(response, "\r\n\r\n");
    re[strlen(re) - strlen(re2)] = '\0';

    return re;
}

char* getClientHeaderInfo(int InfoType, char* InfoTitle, char* header, int InfoNum){
    char* p,*q;
    char* line_split[MAX_LINE], *line_split2[10];
    int i = 0,j = 0;

    p = strtok(header, "\r\n");
    while(p != NULL){
        line_split[i] = p;
        p = strtok(NULL, "\r\n");
        i++;
    }

    if(InfoType == 1){
        q = strtok(line_split[0], " ");
        while(q != NULL){
            line_split2[j] = q;
            q = strtok(NULL, " ");
            j++;
        }
        switch(InfoNum){
            case 0:
                return line_split2[0];
            case 1:
                return line_split2[1];
            case 2:
                return line_split2[2];
            default:
                break;
        }
    }

    return "NOT GET INFO";
}
