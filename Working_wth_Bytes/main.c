#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("cat_photo.png", "ab");
    FILE *clone = fopen("clone_das_sombras.png", "wb");
    int c;
    if(file==NULL)
    {
        fprintf(stderr, "Ocorreu um erro ao tentar abrir o arquivo.\n");
        exit(1);
    }
    
    
    fprintf(clone, (char*)file);
    
    fclose(file);
    fclose(clone);
    
    fprintf(stdout, "================= Arquivo aberto com sucesso! =================\n");
}
