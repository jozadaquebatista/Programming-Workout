#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct node{
    char *nome;
    unsigned short idade;
    struct node *next;
}Node;

int main(){ 
    
    setlocale(0, "portuguese");
    
    Node
    *pessoa1 = (Node*)malloc(sizeof(Node)),
    *pessoa2 = (Node*)malloc(sizeof(Node)),
    *pessoa3 = (Node*)malloc(sizeof(Node));
    
    pessoa1->nome = (char*)malloc(sizeof(char));
    pessoa2->nome = (char*)malloc(sizeof(char));
    pessoa3->nome = (char*)malloc(sizeof(char));    

    strncpy(pessoa1->nome, "José Fulano", 20);
    pessoa1->idade = 18;
    pessoa1->next = NULL;

    strncpy(pessoa2->nome, "Estevão Sicrano", 20);
    pessoa2->idade = 22;
    pessoa2->next = NULL;
    
    strncpy(pessoa3->nome, "Bruno Alguem", 20);
    pessoa3->idade = 30;
    pessoa3->next = NULL;
    
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"............. %d anos.\n", 1, pessoa1->nome, pessoa1->idade);
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"......... %d anos.\n", 2, pessoa2->nome, pessoa2->idade);
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"............ %d anos.\n", 3, pessoa3->nome, pessoa3->idade);
    
    pessoa1->next = pessoa3;
    pessoa2->next = pessoa2;
    pessoa3->next = pessoa1;
    
    fprintf(stdout, "\n");
    
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"............ %d anos.\n", 1, pessoa1->next->nome, pessoa1->next->idade);
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"......... %d anos.\n", 2, pessoa2->next->nome, pessoa2->next->idade);
    fprintf(stdout, "Nome e idade da %dº pessoa: \t\"%s\"............. %d anos.\n", 3, pessoa3->next->nome, pessoa3->next->idade);
    
    free(pessoa1);
    free(pessoa2);
    free(pessoa3);
    
    fprintf(stdout, "\nQuantidade de Nós: %d\n", i);
     
    return 0;
}
