#include "funcoes.h"

int verificaPalavra(char *string){

	char *tmp = (char*)malloc(strlen(string)*sizeof(char));

	memset(tmp, 2, strlen(string));
	string+=strlen(string);
	for(int i=strlen(string), j = 0; i >= 0; i-- && j++ && tmp++ && string--)
		tmp = string;

	printf("tamanho de tmp(%s): %d\ntamanho de string(%s): %d\n", tmp, strlen(tmp), string, strlen(string));

	fprintf(stdout, "=> %s\n", tmp);

	if(strncmp(string, tmp, strlen(string))==0){
		fprintf(stdout, "Strings iguais!\n");
		return 1;}
	else{
		fprintf(stdout, "Strings diferentes!\n");
		return 0;}
}

char *touppercase(char *string){

	char tmp[strlen(string)];

	for(int i=0; i < strlen(string); i++)
		string[i] = toupper(string[i]);
		
	return string;
}