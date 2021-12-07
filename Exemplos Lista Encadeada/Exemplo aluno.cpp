#include "stdio.h"
#include "stdlib.h"


typedef struct aluno{
	char nome[45];
	float nota;
	int cod;
	struct aluno *prox;
}Aluno;

Aluno *inicioLista = NULL;
int tam=0;

void insereInicio(){
	Aluno *aluno = (Aluno*) malloc (sizeof(Aluno));
	
	printf("Nome: ");
	scanf("%s", &aluno->nome);
	
	printf("Nota: ");
	scanf("%f", &aluno->nota);
	
	printf("Cod: ");
	scanf("%d", &aluno->cod);
	
	aluno->prox = inicioLista;
	inicioLista = aluno;
	
	printf("\n\n");
	tam++;
}


void insereFim(){
	Aluno *aluno = (Aluno*) malloc (sizeof(Aluno));
	
	printf("Nome: ");
	scanf("%s", &aluno->nome);
	
	printf("Nota: ");
	scanf("%f", &aluno->nota);
	
	printf("Cod: ");
	scanf("%d", &aluno->cod);
	
	aluno->prox = NULL;
	
	
	if(inicioLista == NULL){
		aluno->prox = inicioLista;
		inicioLista = aluno;
	}else{
		Aluno *aux = (Aluno*) malloc (sizeof(Aluno));
		aux = inicioLista;
		
		while(aux != NULL && aux->prox != NULL){
			aux = aux->prox;
		}
		
		aux->prox = aluno;
	}
	tam++;
}

void buscar(){
	int busca;
	printf("Insira o cod do aluno a ser buscado: ");
	scanf("%d", &busca);
	
	Aluno *aux = (Aluno*) malloc (sizeof(Aluno));
	aux = inicioLista;
	
	while(aux != NULL && aux->cod != busca){
		aux = aux->prox;
	}
	
	if(aux->cod == busca){
		printf("Acheii");
	}else{
		printf("Nao Achei");
	}
}


void imprimir(){
	Aluno *aux = (Aluno*) malloc (sizeof(Aluno));
	
	aux = inicioLista;
	
	while(aux != NULL){
		printf("\n\nNome: %s", aux->nome);
		printf("\nNota: %.2f", aux->nota);
		printf("\nCod: %d", aux->cod);
		aux = aux->prox;
	}
	
}

void remover(){
	int busca;
	printf("Insira o cod do aluno a ser removido: ");
	scanf("%d", &busca);
	
	Aluno *aux, *remover = (Aluno*) malloc (sizeof(Aluno));
	aux = inicioLista;
	remover = NULL;
	
	if(inicioLista != NULL && inicioLista->cod == busca){
		remover = inicioLista;
		inicioLista = remover->prox;
	}
	
	else{
		
	while(aux != NULL && aux->prox != NULL && aux->prox->cod != busca){
		aux = aux->prox;
	}
	
	if(aux != NULL && aux->prox != NULL){
	    remover = aux->prox;
		aux->prox = remover->prox;
	}
	
	if(remover != NULL){
		free(remover);
	}
  }
  tam--;
}

void somatorio(){
	Aluno *aux = (Aluno*) malloc (sizeof(Aluno));

	float somatorio = 0;
	aux = inicioLista;
	
	while(aux != NULL){
		somatorio = aux->nota + somatorio; 
		aux = aux->prox;
	}
	
	printf("Media de Notas: %.2f\n", somatorio/tam);
}

void liberarMemoria(){
	Aluno *aux =  (Aluno*) malloc (sizeof(Aluno));
	Aluno *proxNode = (Aluno*) malloc (sizeof(Aluno));
	
	aux = inicioLista;
	
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


int main(){
	int op;
	
	printf("1 - ADD INICIO\n");
	printf("2 - ADD FIM\n");
	printf("3 - ADD BUSCAR\n");
	printf("4 - ADD IMPRIMIR\n");
	printf("5 - DELETE\n");
	printf("6 - MEDIA GERAL\n");
	printf("7 - FREE\n");
	printf("0 - EXIT\n");
	
	do{
		printf("\nOpcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
			   insereInicio();
			break;
			
			case 2:
			   insereFim();
			break;
			
			case 3:
			   	buscar();
			break;
			
			case 4:
			   imprimir();
			break;
			
			case 5:
			   remover();
			break;
			
			case 6:
			   somatorio();
			break;
			
			case 7:
			   liberarMemoria();
			break;
			
			case 0:
			   exit(1);
			break;
			
			default:
				printf("Opcao invalida\n");
			break;
		}
	}while(1);

}
