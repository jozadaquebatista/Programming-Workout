#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{  

  char *arq= (char*)argv[1];

  if(arq==NULL)
  {
    perror("Voce nao passou o arquivo para encriptar menininho HAHAHAHAHA menininho ...\n");
    exit(1); 
  }

  FILE *pr= fopen(arq,"rb"),
       *pw= fopen("bloco_de_dados.txt","ab");
 
  FILE *buf= (FILE*)malloc(sizeof(pr));
  
  while(!feof(pr)){
    fread(buf,1,1,pr);
    fwrite(buf,1,1,pw);
  }
  
  fclose(pr);
  fclose(pw);
  
  char *linha1 = "====================== SUCESS! =======================\n";
  char *linha2 = "\a\n\n\nDid by < Jozadaque Batista >!\n\t\t\tClosing Transmission ...\n\n";
  
  for(int i=0; i < strlen(linha1); i++)
  {
    for(int j=0; j < 10000000; j++);
    fprintf(stdout, "%c", linha1[i]);
  } 
  for(int i=0; i < strlen(linha2); i++)
  {
    for(int j=0; j < 10000000; j++);
    fprintf(stdout, "%c", linha2[i]);
  }
    
  return 0;
}
