#include <stdio.h>
#include <stdlib.h>


//Estrutura base do n�.
struct node{
    int dado;
    struct node *prox;
};

 
//typedef para criar um tipo te dado para referenciar a struct
typedef struct node Node;

 
//Fun��o pra imprimir o n� na tela.
void imprimeNode(Node *p){
	
    printf("Mostrando a lista:\n\n"); 
    if(p != NULL){ //verificando a cabe�a da lista
    	
        do{	
            printf("%d -> ", p->dado); //Imprimindo o valor do N�
            
            p = p->prox; //Atualizando o N�
			      
        }while(p != NULL);  
        
        if(p == NULL){
        	printf("NULL\n");
		}
    }
    else{
        printf("Lista vazia.");
    }
}
 
int main(void){
	
	//Criando meus N�s
    Node *pNode1 = NULL;
    Node *pNode2 = NULL;
    Node *pNode3 = NULL;
    Node *pNode4 = NULL;
    Node *pNode5 = NULL;
     
    //Fzedo aloca�ao dinamica e associando os dados.
    pNode1 = (Node*) malloc(sizeof(Node));
    pNode1->dado = 10;
     
    pNode2 = (Node*) malloc(sizeof(Node));
    pNode2->dado = 20;
     
    pNode3 = (Node*) malloc(sizeof(Node));
    pNode3->dado = 30;
    
    pNode4 = (Node*) malloc(sizeof(Node));
    pNode4->dado = 40;
     
    pNode5 = (Node*) malloc(sizeof(Node));
    pNode5->dado = 50;
     
    //Conectando os n�s
    pNode1->prox = pNode2;
    pNode2->prox = pNode3;  
    pNode3->prox = pNode4;
    pNode4->prox = pNode5;
    pNode5->prox = NULL;
    
    //Mostrando a lista encadeada
    if(pNode1 != NULL){
        imprimeNode(pNode1); //pNode1 � a cabe�a da lista
    }
    
if(pNode1 != NULL){
    free(pNode1);
    free(pNode2);
    free(pNode3);
    free(pNode3);
    free(pNode4);
    
    printf("Memoria Liberada\n");
}
  return 0;
}
