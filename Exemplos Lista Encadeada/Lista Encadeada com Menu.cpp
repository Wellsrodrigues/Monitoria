#include <stdio.h>
#include <stdlib.h>

// struct "node" possui dois campos
typedef struct node{
	int dado; // inteiro "v"
	struct node *prox; // ponteiro para o próximo elemento
}Node;


// variáveis ponteiros globais que guardam referência
// para a cabeça da lista e para o nó corrente
// cabeca da lista encadeada (começa com NULL)
Node *cabeca = NULL;
Node *corrente = NULL;


// função para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo Node
Node * criar_lista(int valor){
	// aloca espaço em memória
	Node * p = (Node*)malloc(sizeof(Node));

	// verifica se houve falha na alocação de memória
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		exit(1);
	}

	// se chegou aqui é porque foi feita a alocação com sucesso
	p->dado = valor; // atribui o valor passado
	p->prox = NULL; // o próximo é NULL

	// faz a cabeca e o corrente apontar para p
	cabeca = corrente = p;
	// retorna o ponteiro alocado
	return p;
}


// função que adiciona um elemento à lista
// recebe a cabeca e o elemento a ser adicionado
// o elemento é inserido no FINAL da lista
Node* adicionar_lista(int v){
	
	// verifica se a cabeca é NULL (lista vazia), se for NULL,
	// então retorna o retorno da função criar_lista
	if(cabeca == NULL){
		return criar_lista(v);
	}

	// se chegou aqui é porque a lista NÃO é vazia
	// aloca espaço em memória
	Node * p = (Node*)malloc(sizeof(Node));

	// verifica se houve falha na alocação de memória
	if(p == NULL){
		printf("\nFalha ao alocar memoria\n");
		exit(1);
	}

	// atribui valores
	p->dado = v;
	p->prox = NULL;

	// insere no FINAL da lista (obs.: também poderia ser no início)
	// aqui será feita a inserção no final,
	// a inserção no início fica como um desafio ;-)
	// para inserção no final, fazemos com que o próximo do nó
	// corrente aponte para o "p"
	corrente->prox = p;
	// o corrente passar a ser o "p"
	corrente = p;

	// retorna o ponteiro alocado
	return p;
}


// função que imprime a lista
void imprimir_lista(){
	// variável ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "cabeca"
	Node *aux = cabeca;

	// enquanto "aux" for diferente de NULL
	while(aux != NULL){
		// imprime o valor
		printf("%d ", aux->dado);
		// aponta para o próximo elemento da lista
		aux = aux->prox;
	}
}


// função para verificar se a lista está vazia
// retorna 1 se estiver vazia e 0 caso contrário
int lista_vazia(){
	// se cabeca for NULL, então a lista está vazia
	if(cabeca == NULL)
		return 1;
	return 0;
}


// função para buscar um elemento na lista
// essa função recebe o valor a ser buscado e um ponteiro para ponteiro "ant"
// o "ant" servirá para guardarmos o anterior do elemento encontrado, pois
// iremos utilizar na remoção, assim fica mais otimizado para não ter que
// percorrer a lista novamente pois precisa-se do elemento anterior ao elemento
// que irá ser removido para ajustar corretamente a lista
// retorna o ponteiro para o elemento encontrado ou NULL se não encontrar
Node * buscar_elemento(int v, Node **ant){
	// se a lista estiver vazia, então não possui elementos,
	// portanto, retorna 0 indicando que NÃO achou.
	if(lista_vazia() == 1)
		return NULL;

	// variável "p" para percorrer a lista
	Node *p = cabeca;
	// variável "aux_ant" para guardar o anterior
	Node *aux_ant = NULL;
	// flag "achou" que indica se achou o elemento
	int achou = 0;

	// percorre a lista
	while(p != NULL)
	{
		// se achou, então retorna 1
		if(p->dado == v)
		{
			achou = 1;
			break;
		}
		// atualiza o "aux_ant"
		aux_ant = p;
		// aponta para o próximo
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

	// se chegou aqui, então não achou
	return NULL;
}

// função que remove um elemento da lista
// retorna 1 se conseguiu remover e 0 caso contrário
int remover_elemento(int v){
	// variável que guarda a referência para o elemento anterior
	// do elemento que vai ser removido
	Node *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a referência para o "ant" (ponteiro para ponteiro)
	// "elem" é o elemento que será removido
	Node * elem = buscar_elemento(v, &ant);

	// se for NULL, é porque não existe, então retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, é porque o elemento existe e será removido

	// se o anterior for diferente de NULL, então
	// faz o próximo do anterior apontar para o próximo
	// do elemento que será removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido é igual ao corrente, ou seja,
	// é o último elemento, então faz o corrente apontar para o anterior
	if(elem == corrente)
		corrente = ant;

	// se o elemento a ser removido é igual a cabeca, ou seja,
	// é o primeiro elemento, então faz a cabeca apontar para o próximo
	// do elemento a ser removido
	if(elem == cabeca)
		cabeca = elem->prox;

	// por último, dá um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// função que retorna o tamanho da lista
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

// função principal
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
