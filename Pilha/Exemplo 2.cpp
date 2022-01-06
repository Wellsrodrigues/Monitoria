#include  <stdio.h>
#include  <stdlib.h>


typedef struct node{
	int num;
	struct node *prox;
}Node;

Node *topo = NULL;


void insere(int valor){
	Node *novo = (Node*) malloc (sizeof(Node));
	
	novo->num = valor;
	
	novo->prox = topo;
	topo = novo;
}

void remove(){
	if(topo == NULL){
		printf("Pilha vazia");
	}else{
		Node *remov = (Node*) malloc (sizeof(Node));
		
		remov = topo;
		topo = topo->prox;
		free(remov);
	}
}

void top(){
	if(topo == NULL){
		printf("Pilha vazia");
	}else{
		printf("Topo: %d\n", topo->num);
	}
}

void imprimi(){
	if(topo == NULL){
		exit(1);
	}else{
	
	Node *aux = (Node*) malloc (sizeof(Node));
	
	aux = topo;
	
	while(aux != NULL){
		printf("%d\n", aux->num);
		aux = aux->prox;
	}
  }
}

main(){
	
	insere(10);
	insere(1);
	insere(7);
	
	imprimi();
	
	printf("\nremocao\n");
	remove();
	
	imprimi();
}

