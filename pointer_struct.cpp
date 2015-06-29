#include <iostream>
#include <string.h>
#include <stdio.h>

typedef struct pessoa{

    char *nome;

    /*void Pessoa(){
        strncpy(nome, "Jozadaque", 10);
    }*/
    void falar();
    void getNome(){
        return nome;
    }
} Pessoa;

int main(){

    Pessoa *objetoP1;
    
    fprintf(stdout, "o nome do objeto no endereco: \"%s\" e': %s\n", objetoP1, objetoP1->getNome());

    return 0;
}
