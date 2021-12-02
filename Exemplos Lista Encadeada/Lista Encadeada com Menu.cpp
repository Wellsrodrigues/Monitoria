#include <stdio.h>
#include <stdlib.h>

// struct "node" possui dois campos
typedef struct node{
	int dado; // inteiro "v"
	struct node *prox; // ponteiro para o pr�ximo elemento
}Node;


// vari�veis ponteiros globais que guardam refer�ncia
// para a cabe�a da lista e para o n� corrente
// cabeca da lista encadeada (come�a com NULL)
Node *cabeca = NULL;
Node *corrente = NULL;


// fun��o para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo Node
Node * criar_lista(int valor){
	// aloca espa�o em mem�ria
	Node * p = (Node*)malloc(sizeof(Node));

	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		exit(1);
	}

	// se chegou aqui � porque foi feita a aloca��o com sucesso
	p->dado = valor; // atribui o valor passado
	p->prox = NULL; // o pr�ximo � NULL

	// faz a cabeca e o corrente apontar para p
	cabeca = corrente = p;
	// retorna o ponteiro alocado
	return p;
}


// fun��o que adiciona um elemento � lista
// recebe a cabeca e o elemento a ser adicionado
// o elemento � inserido no FINAL da lista
Node* adicionar_lista(int v){
	
	// verifica se a cabeca � NULL (lista vazia), se for NULL,
	// ent�o retorna o retorno da fun��o criar_lista
	if(cabeca == NULL){
		return criar_lista(v);
	}

	// se chegou aqui � porque a lista N�O � vazia
	// aloca espa�o em mem�ria
	Node * p = (Node*)malloc(sizeof(Node));

	// verifica se houve falha na aloca��o de mem�ria
	if(p == NULL){
		printf("\nFalha ao alocar memoria\n");
		exit(1);
	}

	// atribui valores
	p->dado = v;
	p->prox = NULL;

	// insere no FINAL da lista (obs.: tamb�m poderia ser no in�cio)
	// aqui ser� feita a inser��o no final,
	// a inser��o no in�cio fica como um desafio ;-)
	// para inser��o no final, fazemos com que o pr�ximo do n�
	// corrente aponte para o "p"
	corrente->prox = p;
	// o corrente passar a ser o "p"
	corrente = p;

	// retorna o ponteiro alocado
	return p;
}


// fun��o que imprime a lista
void imprimir_lista(){
	// vari�vel ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "cabeca"
	Node *aux = cabeca;

	// enquanto "aux" for diferente de NULL
	while(aux != NULL){
		// imprime o valor
		printf("%d ", aux->dado);
		// aponta para o pr�ximo elemento da lista
		aux = aux->prox;
	}
}


// fun��o para verificar se a lista est� vazia
// retorna 1 se estiver vazia e 0 caso contr�rio
int lista_vazia(){
	// se cabeca for NULL, ent�o a lista est� vazia
	if(cabeca == NULL)
		return 1;
	return 0;
}


// fun��o para buscar um elemento na lista
// essa fun��o recebe o valor a ser buscado e um ponteiro para ponteiro "ant"
// o "ant" servir� para guardarmos o anterior do elemento encontrado, pois
// iremos utilizar na remo��o, assim fica mais otimizado para n�o ter que
// percorrer a lista novamente pois precisa-se do elemento anterior ao elemento
// que ir� ser removido para ajustar corretamente a lista
// retorna o ponteiro para o elemento encontrado ou NULL se n�o encontrar
Node * buscar_elemento(int v, Node **ant){
	// se a lista estiver vazia, ent�o n�o possui elementos,
	// portanto, retorna 0 indicando que N�O achou.
	if(lista_vazia() == 1)
		return NULL;

	// vari�vel "p" para percorrer a lista
	Node *p = cabeca;
	// vari�vel "aux_ant" para guardar o anterior
	Node *aux_ant = NULL;
	// flag "achou" que indica se achou o elemento
	int achou = 0;

	// percorre a lista
	while(p != NULL)
	{
		// se achou, ent�o retorna 1
		if(p->dado == v)
		{
			achou = 1;
			break;
		}
		// atualiza o "aux_ant"
		aux_ant = p;
		// aponta para o pr�ximo
		p = p->prox;
	}

	// verifica se achou
	if(achou == 1)
	{
		// se "ant" for diferente de NULL
		if(ant)
			*ant = aux_ant; // guarda "aux_ant"
		return p;
	}

	// se chegou aqui, ent�o n�o achou
	return NULL;
}

// fun��o que remove um elemento da lista
// retorna 1 se conseguiu remover e 0 caso contr�rio
int remover_elemento(int v){
	// vari�vel que guarda a refer�ncia para o elemento anterior
	// do elemento que vai ser removido
	Node *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a refer�ncia para o "ant" (ponteiro para ponteiro)
	// "elem" � o elemento que ser� removido
	Node * elem = buscar_elemento(v, &ant);

	// se for NULL, � porque n�o existe, ent�o retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, � porque o elemento existe e ser� removido

	// se o anterior for diferente de NULL, ent�o
	// faz o pr�ximo do anterior apontar para o pr�ximo
	// do elemento que ser� removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido � igual ao corrente, ou seja,
	// � o �ltimo elemento, ent�o faz o corrente apontar para o anterior
	if(elem == corrente)
		corrente = ant;

	// se o elemento a ser removido � igual a cabeca, ou seja,
	// � o primeiro elemento, ent�o faz a cabeca apontar para o pr�ximo
	// do elemento a ser removido
	if(elem == cabeca)
		cabeca = elem->prox;

	// por �ltimo, d� um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// fun��o que retorna o tamanho da lista
int tamanho_lista(){
	if(lista_vazia())
		return 0;

	Node *aux = cabeca;
	int tam = 0;

	while(aux != NULL)
	{
		tam++;
		aux = aux->prox;
	}
	return tam;
}

// fun��o principal
int main(int argc, char * argv[]){
	int op, num;
	
	 printf("1 - Lista Vazia\n");
	 printf("2 - Criar Lista\n");
	 printf("3 - Adicionar a Lista\n");
	 printf("4 - Imprimir Lista\n");
	 printf("5 - Remover da Lista\n");
	 printf("6 - Buscar na Lista\n");
	 printf("7 - Tamanho Lista\n");
	 printf("0 - Sair\n");

  do{
    printf("OP: ");
		scanf("%d", &op);
		
		switch (op){
			case 1: 
			    if(lista_vazia() == 0)
		            printf("\nA lista NAO esta vazia!!\n");
	            else
		            printf("\nLista vazia!!\n");
			break;
			
			case 2: 
			    printf("Digite um valor para criar a lista: ");
			    scanf("%d", &num);
			    criar_lista(num);
			break;
			
			case 3: 
			    printf("Add valor: ");
			    scanf("%d", &num);
			    adicionar_lista(num); 
			break;
			
			case 4:
			    imprimir_lista();
			break;
			
			case 5:
				printf("Remover valor: ");
			    scanf("%d", &num);
			   	if(remover_elemento(num))
		            printf("\nElemento %d removido com sucesso!\n", num);
            	else
		            printf("\nNAO foi possivel remover o elemento %d\n", num);
			break;

            case 6:
            	printf("Buscar valor: ");
			    scanf("%d", &num);
			   	if(buscar_elemento(num, NULL) != NULL)
		            printf("\nElemento %d encontrado!\n", num);
	            else
	            	printf("\nElemento %d NAO encontrado\n", num);
			break;
			
			case 7:
			  printf("\nTamanho da lista: %d\n", tamanho_lista());
			break;	
						
			case 0: 
			   exit(1); 
			break;
			
			default: printf("Op invalida\n");
		}
		printf("\n\n");

    }while(op != 0);

	return 0;
}
