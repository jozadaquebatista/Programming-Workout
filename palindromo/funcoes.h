/*****************
*	BIBLIOTECAS    *
*	  USADAS       *
******************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

char *string; //String que será recebida

/***************************************
*                                      *
*	FUNÇOES QUE SERÃO CHAMADAS.          *
*                                      *
***************************************/
int verificaPalavra(char *string);
/* Função que verifica se a palavra é palíndroma */

char *touppercase(char *string);
/* Função para deixar a palavra em UPPERCASE.(opcional) */
