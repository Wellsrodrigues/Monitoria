#include "stdio.h"
#include "stdlib.h"

//----------------------------------------------------------------------------------------

//PROCEDIMENTOS PARA AS FUNCOES

int* criaVetor(int);

void imprime(int*, int);

void libera(int*);

void lerVetor(int*, int);

//----------------------------------------------------------------------------------------

//FUNCAO PRINCIPAL

int main(){
	
	int *p = NULL;
	int n;
	
	printf("Informe n: ");
	scanf("%d", &n);
	
	p = criaVetor(n); //chamando as funcoes
	
	lerVetor(p, n);
	
	imprime(p, n);
	
	libera(p);
	
	return 0;
}

//----------------------------------------------------------------------------------------

//FUNCOES

int* criaVetor(int n){
	int *vetor = NULL;
	
	vetor = (int*) malloc(n*sizeof(int));
	
	if(vetor == NULL){
		printf("\nMemoria insuficiente\n");
		exit(1);
	}
	return vetor;
}

void lerVetor(int* v, int tam){
	for(int i=0; i<tam; i++){ 
	   printf("\nValor %d: ", i+1);
	   scanf("%d", &v[i]);
	}
}

void imprime(int* v, int tam){
	printf("\n\nMeu Vetor: ");
	for(int i=0; i<tam; i++){
		printf("%d ", v[i]);
	}
	
}

void libera(int* v){
	free(v);
	v = NULL;
	printf("\n\nMemoria liberada!");
}

