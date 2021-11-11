#include "stdio.h"

	
int main(){
	
	char nome[6] = "false", *p3;
	
	printf("CHAR NORMAL: %s\n\n",nome);
	
    p3 = &nome[0]; //ponteiro char aponta para a primeira posicao do vetor nome
    
//-----------------------------------------------------------------------------------------------------------------------

    //aritmetica de ponteiros: SOMA
    
	*p3 = 't'; //mudando valor da primeira posiçao do vetor nome
	*(p3+1) = 'r'; //somando +1 a primeira posiçao p3 do vetor, acessamos a segunda posicao do vetor
	*(p3+2) = 'u';
	*(p3+3) = 'e';
	*(p3+4) = '!';
	*(p3+5) = '!';
	
	printf("PELA SOMA: %s\n\n",nome);
	
	//percebe-se a formula: *(p3+n) para acessar todas as posicoes do vetor com aritmetica de ponteiros

//-----------------------------------------------------------------------------------------------------------------------


	//aritmetica de ponteiros: SUBTRACAO
	
	p3 = &nome[5]; //mudando valor da ultima posiçao do vetor nome
	*p3 = 'f';
	*(p3-1) = 'a'; //subtraindo -1 da ultima posiçao p3 do vetor, acessamos a penultima posicao do vetor
	*(p3-2) = 'l';
	*(p3-3) = 's';
	*(p3-4) = 'e';
	*(p3-5) = '!';
	
	printf("PELA SUBTRACAO: %s\n",nome); //imprime false invertido, pois inserimos as letras pelo final
	
	//percebe-se a formula: *(p3-n) para acessar todas as posicoes do vetor com aritmetica de ponteiros
}
	
