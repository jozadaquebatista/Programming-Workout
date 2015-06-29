#include "funcoes.h"

/************************************************************
*                                                           *
*	ESTE PROGRAMA TEM POR FINALIDADE SIMPLESMENTE             *
*	O OBJETIVO DE VERIFICAR SE UMA PALAVRA É A mesma          *
*	MESMO AO CONTRÁRIO, EM CASO POSITIVO ISSO CARACTERIZA     *
*	UMA PALAVRA COMO PALINDROMA(mesma palavra tanto de trAs   *
*	para frente), TAMBEM IMPLEMENTANDO O CONCEITO DE MODULA   *
*	ÇÃO, PARA UMA MELHOR MANIPULAÇÃO E VISUALIZALCAO DO CON   *
*	TEUDO, PONTEIRO, PONTEIROS PARA FUNCAO, ETC. @author      *
*                                                           *
*************************************************************/

int main(void){

	setlocale(0, "portuguese");

	string = (char*)malloc(sizeof(char));

	fprintf(stdout, "Este software verifica se uma palavra é um palíndromo, ou seja, se\
 ela é a mesma de trás para frente e vice-versa. Entre com a string que deseja verificar: ");
	scanf("%s", string);

	if(verificaPalavra(string) == 1)
		fprintf(stdout, "\n[ %s ] é um palíndromo!\n\n", touppercase(string));
	else
		fprintf(stdout, "\n[ %s ] não é um palíndromo!\n\n", touppercase(string));

	free(string); /* Funcao para liberar o conteudo da var "string" */
	return 0;
}
