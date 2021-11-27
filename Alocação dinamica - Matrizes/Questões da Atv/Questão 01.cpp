#include "stdio.h"
#include "stdlib.h"


int** alocaMatriz(int**, int, int); //predefinicao da funcao 


//------------------------------------------------------------------------------------------------------


int main(){
	int**mat = NULL;
	int lin, col;
	
	printf("Informe o num de linhas e colunas da matriz: ");
	scanf("%d %d", &lin, &col);
	
	
	mat = alocaMatriz(mat, lin, col); //chamando minha funcao
	
	
	for(int i=0; i<lin; i++){   //imprimindo minha matriz
		for(int j=0; j<col; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	if(mat != NULL){ //liberando memoria n
		for(int i=0; i<lin; i++){
			free(mat[i]);
		} 
		free(mat);
		printf("\nMemoria liberada.");
	}
}


//------------------------------------------------------------------------------------------------------
 
 

int** alocaMatriz(int** matriz, int n, int m){ //minha funcao 
	
	matriz = (int**) malloc (n * sizeof(int)); //alocando linhas
	
	if(matriz == NULL){ //verificando se foi um sucesso
		printf("Memmoria insuficiente para linhas");
		exit(1);
	}
	
	for(int i=0; i<n; i++){ //alocando colunas para cada linha
		matriz[i] = (int*) malloc (m * sizeof(int));
	
		if(matriz == NULL){ //verificando se foi um sucesso
	    	printf("Memmoria insuficiente para colunas");
	    	exit(1);
     	}
	}
	
		for(int i=0; i<n; i++){ //inicializando minha matriz
			for(int j=0; j<m; j++){
				matriz[i][j] = 0;
	    	}
		}
	
	return matriz; //retornando para o main minha matriz criada
		
}
