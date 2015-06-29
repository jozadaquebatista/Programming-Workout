#include <iostream>
#include <string>
#include <locale.h>

class MostraNome{

	private:
		std::string nome;

	public:
		MostraNome(std::string x){

			std::cout << "Essa e um simples mensagem do metodo construtor." << std::endl;
			setNome(x);
		}

		void setNome(std::string x);
		std::string getNome();
};