#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  int num;
  struct node* dir;
  struct node* esq;
}Node;

Node *raiz = NULL;

void inserirEsquerda(Node *, int);


void inserirDireita(Node *no, int valor){
		if(no->dir == NULL){
		Node *novo = (Node*) malloc (sizeof(Node));
		novo->num = valor;
		novo->dir = NULL;
		novo->esq = NULL;
		
		no->dir = novo;
	}
	
	else{
		if(valor > no->dir->num){
			inserirDireita(no->dir, valor);
		}
		
		if(valor < no->dir->num){
			inserirEsquerda(no->dir, valor);
		}
	}
}

void inserirEsquerda(Node *no, int valor){
	if(no->esq == NULL){
		Node *novo = (Node*) malloc (sizeof(Node));
		novo->num = valor;
		novo->dir = NULL;
		novo->esq = NULL;
		
		no->esq = novo;
	}
	
	else{
		if(valor < no->esq->num){
			inserirEsquerda(no->esq, valor);
		}
	    if(valor > no->esq->num){
			inserirDireita(no->esq, valor);
		}
	}
}

void inserirMetodo1(int valor){
	if(raiz == NULL){
		Node *novo = (Node*) malloc (sizeof(Node));
		novo->num = valor;
		novo->dir = NULL;
		novo->esq = NULL;
		raiz = novo;
	}else{
		if(valor < raiz->num){
			inserirEsquerda(raiz, valor);
		}
		if(valor > raiz->num){
			inserirDireita(raiz, valor);
		}
	}
}

//-------------------------------------------------------------------------------------------------------------


void inserirMetodo2(Node** raiz, int num){
  
  if(*raiz == NULL){ // Raiz vazia
    *raiz = (Node*)malloc(sizeof(Node)); 
    
    (*raiz)->esq = NULL; 
    (*raiz)->dir = NULL; 
    (*raiz)->num = num; 
    
  }else{
  	
    if(num < (*raiz)->num){ // verificar se é menor que o no principal
      inserirMetodo2(&(*raiz)->esq, num); //insere a esquerda
    }
    
    if(num > (*raiz)->num){ //verifica se e maior
      inserirMetodo2(&(*raiz)->dir, num); //insere a direita
    }
  }
}


void imprimir(Node *arvore){ //impressao: esquerda - raiz -  direita
	if(arvore != NULL){
		imprimir(arvore->esq);
		printf("%d ", arvore->num);
		imprimir(arvore->dir);
	}
}

main(){
	
   inserirMetodo1(10);
   
   inserirMetodo2(&raiz, 11);
   
   imprimir(raiz);
   
}
