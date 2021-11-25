#include "stdio.h"
#include "stdlib.h"


int main(){
	
	FILE* arq;
	int **mat = NULL;
	int lin, col;
	
	arq = fopen("arq.txt", "r"); //abrindo meu arquivo com a matriz
	
	if(arq == NULL){
		printf("Erro ao abrir o arquivo");
	}
	
	fscanf(arq, "%d %d", &lin, &col); //lendo o numero de linhas e colunas no arquivo
	
	mat = (int**) malloc (lin * sizeof(int));
	
	if(mat == NULL){
		printf("Memoria Insufiente");
		exit(1);
	}
	
	for(int i=0; i<lin; i++){
		mat[i] = (int*) malloc (col * sizeof(int));
		
		if(mat[i] == NULL){
	    	printf("Memoria Insufiente");
		    exit(1);
	    }
	}
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
		    fscanf(arq, "%d", &mat[i][j]); //adicionando os elementos do meu arquivo na minha matriz
    	}
	}
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
		    printf("%d ", mat[i][j]); //imprimindo minha matriz
    	}
    	printf("\n");
	}
	
	for(int i=0; i< lin; i++){
		free(mat[i]);
	}
	
	free(mat);
	
	
	fclose(arq);
	
}
