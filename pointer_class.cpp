#include <iostream>
#include <string.h>
#include <stdio.h>

class Pessoa{

private:

    char *nome;
public:

    Pessoa(){
        strncpy(nome, "Jozadaque", 10);
    }
    /*~Pessoa(){
        std::cout << "Objeto, " << "has been killed! jajajaja :)" << std::endl;
    }*/
    void falar();
    char *getNome(){
        return nome;
    }
};

int main(){

    Pessoa objetoP1;
    
    fprintf(stdout, "o nome do objeto no endereco: \"%s\" e': %s\n", objetoP1, objetoP1.getNome());

    return 0;
}
