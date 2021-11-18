#include "stdio.h"
#include <stdlib.h>


int* criarVetor(int n){
	int *novoVetor = NULL;
	
	novoVetor = (int*) malloc (n * sizeof(int));
	
	if(novoVetor == NULL){
		printf("memoria insuficiente");
		exit(1);
	}
	
	return novoVetor;
}

void liberarMemoria(){

}

void lerValores(){
	
}

void imprimirValores(){
	
}

int main(){
	
	int *vetor = NULL;
	int qtd;
	
	printf("Qtde de elementos do vetor: ");
	scanf("%d", &qtd);
	
	
	vetor = criarVetor(qtd);
	
	lerValores();
	
	imprimirValores();
	
	liberarMemoria();
	

}
