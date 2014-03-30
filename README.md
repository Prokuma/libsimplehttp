libsimplehttp
=============
간단하게 쓰기위해 만든 라이브러리입니다.
원래 저 혼자 쓸 생각이였지만,
공개하면 좋을거 같아서 GPLv3의 라이센스로 공개합니다!

크게 httpio와 httputil로 분류되어있습니다.

httpio.h의 함수

httpio.h는  client->server랑
server->client로 보낼 수 있는 함수를 내장하고 있습니다.

Example

Server->Client
```C
char response[30000];
int sockfd = server_bind("127.0.0.1", 80, response, 30000);
server_send(200,"OK","<h1>HELLO</h1>", sockfd, 30000);
```

Client->Server
```C
char response[30000];
client_send("GET", "127.0.0.1", "", response,"/",80);
printf("%s\n", resposne);
```

httputil.h는 http분석 관련한 함수들을 내장 하고 있습니다.

아직 완성되지 않았으므로 나중에 설명을 적겟습니다
