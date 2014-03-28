libsimplehttp, Simple HTTP library
=============
간단한 http라이브러리입니다.
사용 방법은

Server
int server_bind(서버주소(char* 형),포트(int형),값을 받을 char Array(char* 형),Array의 크기(int형));
server_send(보낼 값(char* 형), sockfd(int형));

Client
client_send(타입(char* 형), 서버주소(char* 형"),파라메터(char*값)(GET일경우 ""로), 값을 받을 char Array(char*형),도큐멘트 경로(char* 형));


임시설명으므로 곧 바뀔겁니다
