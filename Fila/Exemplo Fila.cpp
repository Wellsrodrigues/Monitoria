#include <stdio.h>
#include <stdlib.h>

//---------------------------------------- NO -------------------------------------------

typedef struct Node{
 int num;
 struct Node *prox;
}node;

int tam;
node *FILA = NULL;

//---------------------------------------- INICIA -------------------------------------------

void inicia(){
  	FILA = NULL;
    tam=0;
}

//---------------------------------------- MALLOC -------------------------------------------

node *aloca(){
 node *novo = (node*) malloc(sizeof(node));
 
 if(novo == NULL){
    printf("Sem memoria disponivel!\n");
    exit(1);
 }
	return novo;
}

//---------------------------------------- ADD -------------------------------------------

void insere(){ //so insere no final
 node *novo = aloca();

 printf("Novo elemento: ");
 scanf("%d", &novo->num);
 novo->prox = NULL;

 if(FILA == NULL){
 	FILA = novo; //adicionando no comeco da fila, pois ela esta vazia
 }
 else{
 	
  node *aux = FILA;

  while(aux->prox != NULL){ //buscando o final da fila
  	aux = aux->prox;
  }
  aux->prox = novo; //adicionado depois do ultimo da fila
 }
 tam++;
}

//---------------------------------------- DELETE -------------------------------------------

void retira(){ //so retira no inicio
	
 if(FILA->prox == NULL){
    printf("Fila ja esta vazia\n");
 }else{
  node *aux = FILA->prox; //aux recebe a cabeca da fila
  FILA->prox = aux->prox; // a cabeca da fila recebe o seguinte ao aux, ou o segundo elemento
  
  if(aux != NULL){
    printf("Retirado: %d\n", aux->num);
  	free(aux);
  }
  
  tam--;
 }

}

//---------------------------------------- IMPRIMIR -------------------------------------------

void exibe(){
 if(FILA == NULL){
    printf("Fila vazia!\n\n");
 }
 else{
   node *aux;
   aux = FILA;

   printf("Fila: ");
   
   while(aux != NULL){
      printf("%d  ", aux->num);
      aux = aux->prox;
    }
    
	printf("\n\n");
  }
}

//---------------------------------------- FREE -------------------------------------------

void libera(){
 if(FILA == NULL){
 	printf("Fila vazia!\n");
 }	
 else{
  node *proxNode, *atual;

  atual = FILA;
  
    while(atual != NULL){
      proxNode = atual->prox;
      free(atual);
      atual = proxNode;
    }
    
    if(atual == NULL){
    	printf("Fila foi esvaziada com sucesso!");
	}
  }
}

//---------------------------------------- MENU -------------------------------------------

int menu(){
 int opt;

 printf("\n\nEscolha a opcao\n\n");
 printf("1. Zerar fila\n");
 printf("2. Exibir fila\n");
 printf("3. Adicionar Elemento na Fila\n");
 printf("4. Retirar Elemento da Fila\n");;
 printf("0. Sair\n");
 
 printf("Opcao: ");
 scanf("%d", &opt);
 printf("\n\n");
 return opt;
}

//---------------------------------------- MAIN -------------------------------------------

int main(){
 int op;
 
 while(1){
 
 op = menu();
   
 switch(op){
    case 0:
      libera();
      exit(1);
    break;

    case 1:
      libera();
      inicia();
    break;

   case 2:
      exibe();
   break;

   case 3:
      insere();
   break;

   case 4:
      retira();
   break;

   default:
      printf("Comando invalido\n\n");
   }
 }

 return 0;
}

 


