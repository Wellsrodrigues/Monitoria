#include "stdio.h"
#include "stdlib.h"

//STRUCT QUE DEFINE UM NO
typedef struct No{
	int num;
	struct No *prox;
}Node;

//STRUCT QUE DEFINE UMA LISTA (SUCESSAO DE NÓS)
typedef struct{
	int tam;
	Node *inicio;
}Lista;


//----------------------------------------------------------------------------

Lista *IniciaLista(){
	Lista *lista = (Lista*) malloc (sizeof(Lista));
	
    lista->inicio = NULL;
    lista->tam = 0;
    
    return lista;
}

//----------------------------------------------------------------------------

Node *Malloc(Node *no){
	no = (Node*) malloc (sizeof(Node));
	
	if(no == NULL){
		printf("Memoria Insuficiente\n");
		exit(1);
	}
	
	return no;
}

//----------------------------------------------------------------------------------

void InserirInicio(Lista *list){
	
	Node *No = Malloc(No); //CRIANDO NOVO NÓ

	printf("Add: ");
	scanf("%d", &No->num); //ATRIBUINDO VALOR DO NOVO NÓ
	
	No->prox = list->inicio; //O PROX DO NO RECEBE NULL
	list->inicio = No; //INICIO DA LISTA RECEBE O NOVO NÓ, POIS ESTAMOS INSERINDO NO INICIO
	list->tam++; //TAMANHO DA LISTA É ATUALIZADO
}

//----------------------------------------------------------------------------

void InserirFim(Lista *list){
	
	Node *No = Malloc(No);
	
	printf("Add: ");
	scanf("%d", &No->num);
	
	No->prox = NULL; //PROX RECEBE NULL, POIS ESTAMOS INSERINDO AO FINAL
	
	if(list->inicio == NULL){ //CASO A LISTA ESTEJA VAZIA, O NO É ATRIBUIDO AO INICIO DA LISTA
		list->inicio = No;
	} 
	
	else{
		Node *aux = Malloc(aux); //NO AUXILIAR PARA PERCORRER A LISTA
		aux = list->inicio;
		
		while(aux->prox != NULL){ //PROCURANDO O ULTIMO ELEMENTO DA LISTA (AQUELE CUJO PROX = NULL)
			aux = aux->prox;
	    }
	    
		aux->prox = No; //ARMAZENANDO NOVO DEPOIS DO ULTIMO ELEMENTO DA LISTA
	}	
		list->tam++;
}

//----------------------------------------------------------------------------

void RemoverNo(Lista *list){
	int valor;
	Node *aux = Malloc(aux);
	Node *remove = Malloc(remove);
	
	aux = list->inicio;
	remove = NULL;
	
	printf("Digite o valor a ser removido: ");
	scanf("%d", &valor);
	if(aux != NULL && list->inicio->num == valor){
		remove = list->inicio;
		list->inicio = remove->prox;
	} else{
		while(aux != NULL && aux->prox != NULL && aux->prox->num != valor){
		   aux = aux->prox;
		}
		
		if(aux != NULL && aux->prox != NULL){
			remove = aux->prox;
			aux->prox = remove->prox;
		}
	}
	if(remove != NULL){
		free(remove);
		list->tam--;
    }
}

//----------------------------------------------------------------------------

void Imprimir(Lista *list){
	Node *aux = Malloc(aux);
	aux = list->inicio;
	
	printf("\nLista: ");
	
	while(aux != NULL){
		printf("%d -> ", aux->num);
		aux = aux->prox;
	}
	
	if(aux == NULL){
		printf("NULL\n");
	}
	
	printf("Tamanho da lista: %d\n", list->tam);
}

//----------------------------------------------------------------------------

void liberarMemoria(Lista *list){
	Node *aux = Malloc(aux);
	Node *proxNode = Malloc(proxNode);
	
	aux = list->inicio;
	
	while(aux != NULL){
		proxNode = aux->prox;
		free(aux);
		aux = proxNode;
	}
	if(aux == NULL){
		printf("Memoria Liberada!\n");
		exit(1);
	}
	
}

//----------------------------------------------------------------------------

int main(){
	int op;
	
    Lista *lista;
	lista = IniciaLista();

  printf("1 - ADD INICIO\n2 - ADD FIM\n3 - IMPRIMIR\n4 - DELETAR\n5 - FREE\n0 - EXIT\n\n");

  do{
    printf("OP: ");
		scanf("%d", &op);
		
		switch (op){
			case 1: 
			    InserirInicio(lista); 
			break;
			
			case 2: 
			    InserirFim(lista); 
			break;
			
			case 3:
			    Imprimir(lista);
			break;
			
			case 4:
			    RemoverNo(lista);
			break;
			
			case 5:
			    liberarMemoria(lista);
			break;
			
			case 0: 
			   exit(1); 
			break;
			
			default: printf("Op invalida\n");
		}
		printf("\n\n");

    }while(op != 0);

}


