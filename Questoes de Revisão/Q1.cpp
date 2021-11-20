#include "stdio.h"

int main(){
	char nome[45];
	char sexo;
	
	printf("NOME: ");
	scanf("%s", &nome);
	
	printf("SEXO: ");
	scanf("%s", &sexo);
	
	
	if(sexo == 'F' || sexo == 'f'){
		printf("Bem-vinda %s!\n", nome);
	}
	else{
		printf("Bem-vindo %s!\n", nome);
	}
}
