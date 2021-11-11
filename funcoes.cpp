#include <stdio.h>

//funccao com retorno
int somar(int x, int y){
	
	return (x+y);
}

// funcao sem retorno  
void subtrair(int x, int y){
	printf("subtracao: %d\n", x-y);
}

int main(){
	int c;
	
	c = somar(4, 5); //chamando a funcao somar e atribuindo seu retorno a variavel c
	
	printf("soma: %d\n", c);
	
	
	subtrair(6, 3); //chamando funcao sem retorno
	
}
