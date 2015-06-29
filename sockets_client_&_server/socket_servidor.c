#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  /* Variáveis */
  int sock, mysock, rval;
  struct sockaddr_in server, client;
  char buff[256];

  /* Cria o socket */
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Falha ao criar socket.");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(5000);

  /* Chama o a função bind() */
  if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
  {
    perror("Funcao bind() falhou.");
    exit(1);
  }

  /* Escutar a conexão */
  listen(sock, 5);

  /* Aceitar conexões */
  while(1)
  {
    if((mysock = accept(sock, (struct sockaddr *) 0, 0)) < 0)
      perror("Tentativa de aceitar conexao falhou.");
    else
    {
      memset(buff, 0, sizeof(buff));

      if((rval = recv(mysock, buff, sizeof(buff), 0)) < 0)
	        perror("Nao foi possivel ler o stream do socket.");
      else if(rval == 0)
	        perror("Finalizando conexao!");
      else
	        fprintf(stdout, "MSG: %s\n", buff);

      fprintf(stdout, "Mensagem recebida (rval = %d)\n", rval);
      close(mysock);
      
    }
  }

  return 0;
}
