#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define DATA "Olá mundo de Wonderland!"

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in server;
    struct hostent *hp;
    char buff[1024];
    
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("falha na criacao do socket.");
        exit(1);
    }
    
    server.sin_family = AF_INET;
    
    if((hp = gethostbyname(argv[1])) == 0)
    {
        perror("Funcao gethosbyname() falhou.");
        exit(1);
    }
    
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
    server.sin_port = htons(5000);
   
    if((connect(sock, (struct sockaddr *)&server, sizeof(server))) < 0)
    {
        perror("Conexao Falhou.");
        exit(1);
    }
    
    if((send(sock, DATA, sizeof(DATA), 0)) < 0)
    {
        perror("Envio de mensagem pelo socket falhou.");
        exit(1);
    }
    
    fprintf(stdout, "MSG enviada: %s\n", DATA);
    close(sock);
    
    return 0;
}
