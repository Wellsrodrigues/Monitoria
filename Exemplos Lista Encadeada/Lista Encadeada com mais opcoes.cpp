#include "stdio.h"
#include "stdlib.h"

//CRIANDO STRUCT PARA O NO
typedef struct node{
    int num;
	struct node *prox;	
}node;

//---------------------------------------------------------
int tam;

void inicia(node *LISTA){ //INICIANDO MINHA LISTA DE NOS
 LISTA->prox = NULL;
 tam=0;
}

//---------------------------------------------------------

int vazia(node *LISTA){ //VERIFICANDO SE LISTA ESTA VAZIA
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

//---------------------------------------------------------

node *aloca(){ //FUNCAO ALOCAR MEMORIA E ADICIONAR VALOR PARA UM NO
 node *novo=(node*) malloc(sizeof(node));
 
 if(novo == NULL){
  printf("\nSem memoria disponivel!\n");
  exit(1);
 }else{
     printf("\nNovo elemento: "); 
     scanf("%d", &novo->num);
  return novo;
 }
}

//---------------------------------------------------------

void insereFim(node *LISTA){ 
 node *novo=aloca();
 novo->prox = NULL;
 
 if(vazia(LISTA)) //SE A FUNCAO QUE VERIFICA SE A LISTA TA VAZIA RETORNA 1, ELA ESTA VAZIA E O NO É ADD NO INICIO 
  
  LISTA->prox=novo;
 
 else{ //LISTA NAO VAZIA, ADD NO FINAL
  node *tmp = LISTA->prox;
  
  while(tmp->prox != NULL){  //BUSCANDO O ULTIMO NO
    tmp = tmp->prox;
   }
  tmp->prox = novo; //ATUALIZANDO O ULTIMO NO
 }
 tam++;
}

//---------------------------------------------------------

void insereInicio(node *LISTA){
 node *novo=aloca(); 
 node *oldHead = LISTA->prox; //SALVANDO A POSICAO ATUAL DA LISTA
 
 LISTA->prox = novo; //A CABECA DA LISTA RECEBE O NOVO NO
 novo->prox = oldHead; // O PROX DEPOIS DO NOVO NO É A CABECA ANTERIOR DA LISTA
 
 tam++;
}

//---------------------------------------------------------

void exibe(node *LISTA){ //IMPRIMINDO A LISTA
 
 if(vazia(LISTA)){
  printf("\nLista vazia!\n\n");
  exit(1);
 }
 
 node *tmp;
 tmp = LISTA->prox; //NO QUE PERCORRE TODA A LISTA
 
 printf("Lista:");
 
 while( tmp != NULL){
  printf("%d ", tmp->num); //IMPRIMINDO CADA NO
  tmp = tmp->prox; //ATUALIZANDO O NO PARA IMPRESSAO
 }
 printf("\n\n");
}

//---------------------------------------------------------

void libera(node *LISTA){ //LIBERANDO MEMORIA
 if(!vazia(LISTA)){
  node *proxNode, *atual; //AUXILIARES PARA PERCORRER OS NOS DA LISTA
  
  atual = LISTA->prox; //ATUAL PERCORRE A LISTA
  
  while(atual != NULL){
     proxNode = atual->prox; //SALVANDO O PROX NO 
     free(atual); //LIBERANDO O NO 
     atual = proxNode; //ATUALIZANDO O NO ATUAL
  }
 }
}

//---------------------------------------------------------

void insere(node *LISTA){ //ADICIONANDO EM POSICAO ESPECIFICADA
 int pos,
  count;
 printf("\nEm que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   node *atual = LISTA->prox,
     *anterior=LISTA; 
   node *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->prox;
   }
   anterior->prox=novo;
   novo->prox = atual;
   tam++;
  }
   
 }else
  printf("\nElemento invalido\n\n");  
}

//---------------------------------------------------------

node *retiraInicio(node *LISTA){
 if(LISTA->prox == NULL){
     printf("\nLista ja esta vazia\n");
     exit(1);
 }else{
     node *tmp = LISTA->prox; //SALVANDO O SEGUNDO NO DA LISTA EM TMP
     LISTA->prox = tmp->prox; //PROX DA LISTA RECEBE TERCEIRO NO DA LISTA (PRIMEIRO PULADO)
     tam--;
     return tmp;
 }
    
}

node *retiraFim(node *LISTA){
 if(LISTA->prox == NULL){
    printf("\nLista ja vazia\n\n");
    exit(1);
 }else{
  node *ultimo = LISTA->prox, *penultimo = LISTA; 
    
  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }
    
  penultimo->prox = NULL;
  tam--;
  return ultimo;  
 }
}

//---------------------------------------------------------

node *retira(node *LISTA){
 int opt,
  count;
 printf("\nQue posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &opt);
 
 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   node *atual = LISTA->prox,
     *anterior=LISTA; 
     
   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->prox;
   }
   
  anterior->prox=atual->prox;
  tam--;
  return atual;
  }
   
 }else{
  printf("\nElemento invalido\n\n");
  return NULL;
  }
 }

//---------------------------------------------------------

int main(){
	
   node *LISTA = (node*) malloc(sizeof(node));
   int opt;
   node *tmp; 
   
   if(!LISTA){
           printf("\nSem memoria disponivel!\n");
           exit(1);
        }else{
           inicia(LISTA);
           
 printf("\n\n");
 printf("|             LISTA            |\n");
 printf("|   1 - Zerar lista            |\n");
 printf("|   2 - Exibir lista           |\n");
 printf("|   3 - Adicionar no inicio    |\n");
 printf("|   4 - Adicionar no final     |\n");
 printf("|   5 - Escolher onde inserir  |\n");
 printf("|   6 - Retirar do inicio      |\n");
 printf("|   7 - Retirar do fim         |\n");
 printf("|   8 - Escolher de onde tirar |\n");
 printf("|   9 - Liberar Memoria        |\n");
 printf("|          0 - Sair            |\n"); 
 
do{   
    
 printf("\nOpcao: "); 
 scanf("%d", &opt);
 
 switch(opt){
  case 0:
   libera(LISTA);
   exit(1);
   break;
   
  case 1:
   libera(LISTA);
   inicia(LISTA);
   break;
  
  case 2:
   exibe(LISTA);
   break;
  
  case 3:
   insereInicio(LISTA);
   break;  
   
  case 4:
   insereFim(LISTA);
   break;
   
  case 5:
   insere(LISTA);
   break;
  
  case 6:
   tmp= retiraInicio(LISTA);
   printf("\nRetirado: %3d\n\n", tmp->num);
   break;
   
  case 7:
   tmp= retiraFim(LISTA);
   printf("\nRetirado: %3d\n\n", tmp->num);
   break;
  
  case 8:
   tmp= retira(LISTA);
   printf("\nRetirado: %3d\n\n", tmp->num);
   break;
  
  case 9:
   libera(LISTA);
   printf("Memoria Liberada\n");
   exit(1);
   break;
   
  default:
   printf("\nComando invalido\n\n");
  }
 }while(opt != 0);
}
    return 0;
}
