#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
    WSADATA data;
    SOCKADDR_IN sock;
    struct sockaddr_in endereco_dele;
    int meusock,novosock;
    int tamanho;
void main()
{

    WSAStartup(MAKEWORD(1,0),&data);
    meusock=socket(AF_INET,SOCK_STREAM,0);

    sock.sin_family=AF_INET;
    sock.sin_port=htons(1234);

    bind(meusock,(SOCKADDR*)&sock,sizeof(sock));
    listen(meusock,1);
    tamanho=sizeof(struct sockaddr_in);
    if(novosock=accept(meusock,(struct sockaddr*)&sock,&tamanho)!=-1)
        printf("CONECTADO");

        send(novosock,"Seja Bem Vindo!\n",16,0);
        close(novosock);





}