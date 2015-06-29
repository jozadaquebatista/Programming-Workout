
Pessoa::Pessoa(){

	std::cout << "Iniciado o construtor do pessoa: " << this << std::endl;
}

Pessoa::~Pessoa(){

	std::cout << "Finalizando o construtor do pessoa: " << this << std::endl;
}

void Pessoa::setNome(std::string x){

	nome = x;
}

void Pessoa::setIdade(int i){

	idade = i;
}

std::string Pessoa::getNome(){

	return nome;
}

int Pessoa::getIdade(){

	return idade;
}