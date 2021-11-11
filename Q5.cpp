#include "stdio.h"
#include "string.h"

	
int main(){
	
	char A[6][30]; //matriz de caracteres para 6 nomes diferentes com tamanho maximo de 30
	char busca[30]; // para comparar com a matriz
	int value = 0;
	
	//lendo os nomes
	printf("INSERINDO NOMES...\n");
	for(int i=0; i<6; i++){
		scanf("%s", &A[i]); //armazenando na posicao da matriz
	}
	

	printf("\n\nNOME BUSCADO: ");
	scanf("%s", &busca);
	
	for(int i=0; i<6; i++){
		if(strcmp(busca, A[i]) == 0){ //funçaõ para comparar 2 strings diferentes, caso sejam iguais a funcao retorna 0
			printf("\n\nNOME ENCONTADO NA POSICAO [%d]\n", i);	
			value = 1; //variavel de teste
		}
		//nao posso utilizar IF/ELSE nesse contexto, pois ao nao encontrar igualdade na primeira comparacao ja mostraria erro
    }
    
    if(value != 1)
        printf("\n\nNOME NAO ENCONTADO!\n");	
		//somente apos todas as comparacoes com todas as posicoes posso concluir que nao foi encontrado nada
}
