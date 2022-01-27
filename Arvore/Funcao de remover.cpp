#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  int num;
  struct node* dir;
  struct node* esq;
}Node;


Node* criaArvore(){
  return NULL;
}

int arvoreVazia(Node* raiz){ 
  return raiz == NULL;
}

void inserirArvore(Node** raiz, int num){
  
  if(*raiz == NULL){ // Raiz vazia
    *raiz = (Node*)malloc(sizeof(Node)); 
    
    (*raiz)->esq = NULL; 
    (*raiz)->dir = NULL; 
    (*raiz)->num = num; 
    
  }else{
  	
    if(num < (*raiz)->num){ // verificar se é menor que o no principal
      inserirArvore(&(*raiz)->esq, num); //insere a esquerda
    }
    
    if(num > (*raiz)->num){ //verifica se e maior
      inserirArvore(&(*raiz)->dir, num); //insere a direita
    }
  }
}

void imprimirArvore(Node* raiz){ 
  if(!arvoreVazia(raiz)) {
  	 imprimirArvore(raiz->esq);
    printf(" <%d> ", raiz->num); 
    imprimirArvore(raiz->dir);
  }
}    

int busca(Node* raiz, int num) {
  
  if(arvoreVazia(raiz)) { 
    return 0;
  }
  
  return raiz->num==num || busca(raiz->esq, num) || busca(raiz->dir, num);
}

//-----------------------------------------------------------------------------------

void remover1(Node *n, int valor){ //metodo remover sem recurssividade
	Node *filho = n;
	Node *pai;
	do{
		pai = filho;
		if(valor < filho->num)
			filho = filho->esq;
		else if(valor > filho->num)
			filho = filho->dir;	
	}while(filho!=NULL && filho->num != valor);

	if(filho != NULL){ // nodo com o valor correspondente encontrado
		if(filho->esq == NULL && filho->dir == NULL){ // nodo folha
			if(pai->esq == filho) pai->esq = NULL;
			if(pai->dir == filho) pai->dir = NULL;
		}
		if(filho->esq != NULL && filho->dir == NULL){ // nodo com 1 filho a esquerda
			if(pai->esq == filho) pai->esq = filho->esq;
			if(pai->dir == filho) pai->dir = filho->esq;
		}
		if(filho->esq == NULL && filho->dir != NULL){ // nodo com 1 filho a direita
			if(pai->esq == filho) pai->esq = filho->dir;
			if(pai->dir == filho) pai->dir = filho->dir;
		}
		if(filho->esq != NULL && filho->dir != NULL) // nodo com 2 filhos
		{
			if(filho->esq->dir==NULL){
				filho->num = filho->esq->num;
				filho->esq = NULL;
			}else{
				Node *p = filho->esq;
				Node *aux = p;
				while(p->dir != NULL){
					aux = p;
					p = p->dir;
				}
				aux->dir = NULL;
				filho->num = p->num;
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------

void remover(Node** pRaiz, int numero){ //metodo remover com recurssividade
   
    if(*pRaiz == NULL){  
       printf("\Numero nao existe na arvore!\n");
       return;
    }
    
    if(numero < (*pRaiz)->num){
    	remover(&(*pRaiz)->esq, numero);
	}
    else{
        if(numero > (*pRaiz)->num){
        	remover(&(*pRaiz)->dir, numero);
		}
        else{   
            Node *pAux = *pRaiz;
			   
            if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){ //No nao tem fihos
                free(pAux);
                (*pRaiz) = NULL; 
            }else{    
                if ((*pRaiz)->esq == NULL){ // so tem o filho da direita
                    (*pRaiz) = (*pRaiz)->dir;
                    pAux->dir = NULL;
                    free(pAux);
				    pAux = NULL;
                }else{           
                    if((*pRaiz)->dir == NULL){ //so tem filho da esquerda
                        (*pRaiz) = (*pRaiz)->esq;
                        pAux->esq = NULL;
                        free(pAux); 
					    pAux = NULL;
                    }else{   
                        pAux = (*pRaiz)->esq;  
                        pAux->esq = (*pRaiz)->esq;    
                        pAux->dir = (*pRaiz)->dir;
                        (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                        free((*pRaiz));  
				        *pRaiz = pAux;  
				        pAux = NULL;   
                    }
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------


main(){
	Node *arvore = criaArvore();
	
	inserirArvore(&arvore, 10);
	inserirArvore(&arvore, 15);
	inserirArvore(&arvore, 5);
	
	imprimirArvore(arvore);
	
	printf("\nApos remocao:\n");
	remover(&arvore, 15);
	
	imprimirArvore(arvore);
}
