#include "mostranome.hpp"

int main(int argc, char **argv){

	setlocale(0, "portuguese");

	MostraNome obj("não identificado"), obj2("não identificado");
	obj.setNome("Jozadaque Batista");

	std::cout << "Seu nome e': " << obj.getNome() << "!" << std::endl;
	std::cout << "Seu nome e': " << obj2.getNome() << "!" << std::endl;

	return 0;
}
