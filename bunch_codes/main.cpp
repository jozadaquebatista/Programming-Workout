#include "Pessoa.h"
#include "Mother.h"
#include "Daughter.h"

int main(){
	
	Mother motherObject;
	Daughter daughterObject;

	motherObject.setNome("Maria");
	motherObject.setIdade(51);

	daughterObject.setNome("Joanna");
	daughterObject.setIdade(12);

	std::cout << std::endl << "Nome da mae: " << motherObject.getNome() << std::endl;
	std::cout << "Idade da mae: " << motherObject.getIdade() << std::endl;
	std::cout << std::endl;
	std::cout << "Nome da filha: " << daughterObject.getNome() << std::endl;
	std::cout << "Idade da filha: " << daughterObject.getIdade() << std::endl << std::endl;
}