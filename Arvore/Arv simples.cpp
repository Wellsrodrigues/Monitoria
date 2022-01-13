#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int num;
	struct node *dir;
	struct node *esq;
}Node;

void imprimir(Node *raiz){
	
	if(raiz != NULL){
		printf("%d ", raiz->num);
		imprimir(raiz->esq);
		imprimir(raiz->dir);
	}
}

Node *insere(int valor, Node *esquerda, Node *direita){
	Node *no = (Node*) malloc (sizeof(Node));
	
	if(no == NULL){
		exit(1);
	}
	else{
	    no->num = valor;
	    no->dir = direita;
 	    no->esq = esquerda;
 	    
 	    return no;
    }
}

int main(){
	
	Node *no = insere(2, insere(1,NULL,NULL), insere(3, NULL, insere(60, insere(0, NULL, NULL), NULL)));
	imprimir(no);
}
