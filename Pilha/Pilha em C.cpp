#include  <stdio.h>
#include  <stdlib.h>

//Ordem LIFO (Last In, First Out - Último a Entrar, Primeiro a Sair)


//---------------------------------------- NO -------------------------------------------

typedef struct no{
    int num;
    struct no *prox;
}Node;

Node *topo = NULL;

//--------------------------------- MALLOC ----------------------------------------------

Node *malloc(Node *No){
	No = (Node*) malloc (sizeof(Node));
	
	if(No == NULL){
		printf("\nMemoria Insuficiente para alocacao!\n");
		exit(1);
	}
	return No;
}

//------------------------------------- PILHA VAZIA? -------------------------------------

bool vazia(){
	bool tst = false;
	
	if(topo == NULL){
		tst = true;
	}
	return tst;
}

//-------------------------------------- ADD NA PILHA -------------------------------------

void push(){
	Node *novo = malloc(novo);
	
	printf("Valor: ");
	scanf("%d", &novo->num);
	
	novo->prox = topo;
	topo = novo;
}

//-------------------------------------- REMOVER DA PILHA ---------------------------------

void pop(){
	if(vazia() == true){
		printf("\nPilha Vazia!");
	}
	
	else{
		Node *delet = malloc(delet);
		
		delet = topo;
		topo = topo->prox;
		free(delet);
	}
}

//---------------------------------------- TOPO DA PILHA -----------------------------------

void top(){
	if(vazia() == false){
		printf("\nTopo da pilha: %d\n", topo->num);
	}
	else{
		printf("\nVazio!\n");
	}
	
}

//------------------------------------------ IMPRIMIR -------------------------------------

void imprime(){
	if(vazia() == true){
		printf("\nPilha Vazia!\n");
	}else{
	printf("\n\nPILHA:\n");
	Node *aux = malloc(aux);
	
	aux = topo;
	
	while(aux != NULL){
		printf("%d\n", aux->num);
		aux = aux->prox;
	}
  }
}

//--------------------------------------------- BUSCAR NA PILHA -----------------------------------

void busca(){
	bool achou = false;
	
	if(vazia() == true){
		printf("\nPilha Vazia!\n");
	}
	else{
	   Node *aux = malloc(aux);
	   int busca;
	   
	   printf("Valor buscado: ");
	   scanf("%d", &busca);
	   
	   aux = topo;
	
	   while(aux != NULL){
	        if(aux->num == busca){
		   	    printf("\nEncontrado na Pilha!\n");
		   	    achou = true;
		    }  
		    aux = aux->prox;
	    }    
		    
		if(achou == false){
		    printf("\nNao encontrado!\n");
		}
	}
}

//-------------------------------------------- LIBERAR MEMORIA ----------------------------------

void libera(){
	if(vazia() == true){
		printf("\nPilha Vazia!\n");
	}
     
    else{
       Node *proxNode = malloc(proxNode);
       Node *atual = malloc(atual);
       
       atual = topo;
  
       while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
        
        if(atual == NULL){
		    printf("Pilha esvaziada com sucesso!\n");
	    }
    }
}

//---------------------------------------- MENU -------------------------------------------

void menu(){
	printf("\n\n\t  MENU\n");
	printf("\t1 - PUSH\n");
	printf("\t2 - POP\n");
	printf("\t3 - TOP\n");
	printf("\t4 - PRINT\n");
	printf("\t5 - SEARCH\n");
	printf("\t6 - FREE\n");
	printf("\t0 - EXIT\n");
}

//------------------------------------------- MAIN ----------------------------------------

int main(){
	int op;
	
	while(1){
		
		menu();
		printf("\nOPP: ");
		scanf("%d", &op);
		
		switch(op){
			
			case 0:
				exit(1);
			break;
			
			case 1:
				push();	
			break;
			
			case 2:
				pop();
			break;
			
			case 3:
				top();	
			break;
			
			case 4:
				imprime();
			break;
			
			case 5:
				busca();	
			break;
			
			case 6:
				libera();
				topo = NULL;	
			break;
			
			default:
				printf("\nOpp inexistente!\n");
			break;
		}
	}
	
	
}
