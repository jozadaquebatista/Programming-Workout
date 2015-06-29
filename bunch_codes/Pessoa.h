#include <iostream>

/****************************************
* Classe PESSOA, que irá servir de base *
* para outras classes derivadas. 	    *
*****************************************/

class Pessoa{
	
private:
	std::string nome;
	int idade;
public:
	Pessoa();
	~Pessoa();
	void setNome(std::string x);
	void setIdade(int i);
	std::string getNome();
	int getIdade();
};