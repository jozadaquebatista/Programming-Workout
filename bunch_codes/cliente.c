#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
    WSADATA data;
    SOCKADDR_IN sock;

    int meusock,numbyte;
    char buffer[100];
void main()
{
    int byte;
    char buffer[1024];
    WSAStartup(MAKEWORD(1,0),&data);
    meusock=socket(AF_INET,SOCK_STREAM,0);

    sock.sin_family=AF_INET;
    sock.sin_port=htons(1234);
    sock.sin_addr.s_addr=inet_addr("192.168.1.100");

    if(connect(meusock,(struct sockaddr*)&sock,sizeof(sock))!=-1)
        printf("CONECTADO");
    recv(numbyte=meusock,buffer,100,0);
    buffer[numbyte]='\0';
    printf("%s",buffer);
    close(meusock);
}