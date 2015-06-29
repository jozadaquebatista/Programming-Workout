#include<stdio.h>
#include<stdlib.h>

int main()
{  
  FILE *pr= fopen("cat_photo.png","rb"),
       *pw= fopen("clone_das_sombras.png","ab");
 
  FILE *buf= (FILE*)malloc(sizeof(pr));
  
  while(!feof(pr)){
    fread(buf,1,1,pr);
    fwrite(buf,1,1,pw);
    printf("construindo! ...\n");
  }
  
  fclose(pr);
  fclose(pw);
}
