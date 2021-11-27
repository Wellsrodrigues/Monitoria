#include "stdio.h"
#include "stdlib.h"
#include <locale.h>


//------------------------------------------------------------------------------------------------------

int** alocaMatriz(int** matriz, int n, int m){ //minha funcao 
	
	matriz = (int**) malloc (n * sizeof(int)); //alocando linhas
	
	if(matriz == NULL){ 
	    printf("\nMemmoria Insufiente!");
	    exit(1);
    }
	
	for(int i=0; i<n; i++){ //alocando colunas para cada linha
	
		matriz[i] = (int*) malloc (m * sizeof(int));
	
		if(matriz[i] == NULL){ 
	       printf("\nMemmoria Insufiente!");
	       exit(1);
        }
	}
	
	return matriz; //retornando para o main minha matriz criada		
}

//------------------------------------------------------------------------------------------------------

void lerMatriz(int** mat, int lin, int col){
	
	printf("\nInserindo valores da Matriz\n");
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("matriz[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

//------------------------------------------------------------------------------------------------------

void imprimirMatriz(int** mat, int lin, int col){

	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("| %d ", mat[i][j]);
		}
		printf("|\n");
	}
	printf("\n\n");
}

int** criaTransposta(int** transp, int** mat, int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			transp[j][i] = mat[i][j];
		}
	}
	return transp;
}

//------------------------------------------------------------------------------------------------------

void liberaMatriz(int** A, int**B, int linA, int linB){
	
		for (int i=0; i < linA; i++){
	        free (A[i]);
        }
        free (A);
        
        for (int i=0; i < linB; i++){
	        free (B[i]);
        }
        free (B);
		printf("\n Memoria liberada!");
}

void calculaMaiores(int** mat, int lin, int col){
	int maior, segMaior, terMaior;
	
    maior= mat[0][0];
	segMaior = maior;
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			if (mat[i][j] > maior){
				terMaior = segMaior;
				segMaior = maior;
                maior = mat[i][j];
            }
		
        }
    }

	printf("Maiores elementos: %d %d %d\n", maior, segMaior, terMaior);
}   

//------------------------------------------------------------------------------------------------------

int main(){
	
	setlocale(LC_ALL, "Portuguese"); //permite usar simbolos nos printf's, nao tem nada haver com matrizes e alocacao

	int** matriz = NULL;
	int** transposta = NULL;
	
	int N, M;
	
	printf("Qtd de linha e de colunas da matriz: ");
	scanf("%d %d", &N, &M);
	
	matriz = alocaMatriz(matriz, N, M);
	
	lerMatriz(matriz, N, M);
	
//------------------------------------------------------------------------------------------------------
	
	transposta = alocaMatriz(transposta, M, N);
	
	transposta = criaTransposta(transposta, matriz, M, N);
	
	printf("\n\nMatriz Normal:\n\n");
	imprimirMatriz(matriz, N, M);
	
	printf("\nMatriz Transposta:\n\n");
	imprimirMatriz(transposta, M, N);
	
	
	
//------------------------------------------------------------------------------------------------------

	calculaMaiores(matriz, N, M);
	
//------------------------------------------------------------------------------------------------------
	
	liberaMatriz(matriz, transposta, N, M);

	
}
