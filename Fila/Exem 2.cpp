#include <stdio.h>
#include <stdlib.h>

typedef struct node{
 int num;
 struct node *prox;
}Node;

Node *FILA = NULL;

void insere(int valor){
	Node *novo = (Node*) malloc (sizeof(Node));
	
	novo->num = valor;
	novo->prox = NULL;
	
	if(FILA == NULL){
		FILA = novo;
	}else{
		Node *aux;
		aux = FILA;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		
		aux->prox = novo;
	}
}

void remove(){
	if(FILA == NULL){
		printf("VAZIA");
	}else{
		Node *remov;
		remov = FILA;
		FILA = remov->prox;
		free(remov);
	}
}

void imprimir(){
if(FILA == NULL){
		printf("VAZIA");
	}else{
		Node *aux;
		
		aux = FILA;
		
		while(aux != NULL){
			printf("%d - ", aux->num);
			aux = aux->prox;
		}
	}	
}

main(){
	insere(10);
	insere(1);
	insere(7);
	
	imprimir();
	
	printf("\nremocao\n");
	remove();
	
	imprimir();
}
