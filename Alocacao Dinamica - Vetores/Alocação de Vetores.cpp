#include "stdio.h"
#include "stdlib.h"


int main(){
	
	int *vet = NULL; //ponteiro apontando para NULL
	int tam;
	
	
	printf("Tamanho: ");
	scanf("%d", &tam);
	
	vet = (int*)malloc(tam*sizeof(int)); //alocacao para n espacos de memoria do tipo inteiro
	
	if(vet == NULL){ //verificando se a memoria foi alocada
		printf("Memoria insuficiente");
		exit(1); // o programa encerra
	}
	
	for(int i=0; i<tam; i++){ //lendo os valores do meu vetor
		printf("\nValor %d: ", i+1);
		scanf("%d", &vet[i]);
	}
	
	printf("\n\nMeu vetor: ");
	
	for(int i=0; i<tam; i++){ //imprimindo os valores do vetor
		printf("%d ", vet[i]);
	}
	
	if(vet != NULL){ //liberando a memoria alocada anteriormente
		free(vet);
		vet = NULL;
		printf("\nConcluido com sucesso\n");
	}
	

	return 0;
}
