#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{  
  char *arq= (char*)argv[1];

  if(arq==NULL)
  {
    perror("Voce nao passou o arquivo para desencriptar menininho HAHAHAHAHA ...\n");
    exit(1); 
  }

  FILE *pr= fopen(arq,"rb"),
       *pw= fopen("clone_das_sombras.png","ab");
 
  FILE *buf= (FILE*)malloc(sizeof(pr));
  
  while(!feof(pr)){
    fread(buf,1,1,pr);
    fwrite(buf,1,1,pw);
  }
  
  fclose(pr);
  fclose(pw);
  
  fprintf(stdout, "====================== SUCESS! =======================\n");
  fprintf(stdout, "\a\n\n\nDid by < Jozadaque Batista >!\n\t\t\tClosing Transmission ...\n\n");
  
  return 0;
}
