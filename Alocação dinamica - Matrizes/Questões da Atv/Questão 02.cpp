#include "stdio.h"
#include "stdlib.h"
#include <locale.h>

//------------------------------------------------------------------------------------------------------

double** alocaMatriz(double** matriz, int n, int m){ //minha funcao 
	
	matriz = (double**) malloc (n * sizeof(double)); //alocando linhas
	
	if(matriz == NULL){ 
	    printf("\nMemmoria Insufiente!");
	    exit(1);
    }
	
	for(int i=0; i<n; i++){ //alocando colunas para cada linha
	
		matriz[i] = (double*) malloc (m * sizeof(double));
	
		if(matriz[i] == NULL){ 
	       printf("\nMemmoria Insufiente!");
	       exit(1);
        }
	}
	
	return matriz; //retornando para o main minha matriz criada		
}

//------------------------------------------------------------------------------------------------------

void lerMatriz(double** mat, int lin, int col, char nome){
	
	printf("\nInserindo valores da Matriz %c\n", nome);
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("%c[%d][%d]: ", nome, i, j);
			scanf("%lf", &mat[i][j]);
		}
	}
}

//------------------------------------------------------------------------------------------------------

void imprimirMatriz(double** mat, int lin, int col, char nome){
	
	printf("\n\t\tMatriz %c:\n", nome);
	
	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			printf("\t| %.2lf ", mat[i][j]);
		}
		printf("|\n");
	}
}

//------------------------------------------------------------------------------------------------------

void liberaMatriz(double** A, double** B, double** C, int lin){
		for (int i=0; i < lin; i++){
	        free (A[i]);
	        free (B[i]);
	        free (C[i]);
        }
        
        free (A);
        free (B);
        free (C);
        
		printf("\n Memoria liberada!");
}

double** somarMatrizes(double** C, double** A,  double** B, int lin, int col){

	for(int i=0; i<lin; i++){
		for(int j=0; j<col; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

//------------------------------------------------------------------------------------------------------

int main(){
	
	setlocale(LC_ALL, "Portuguese"); //permite usar simbolos nos printf's, nao tem nada haver com matrizes e alocacao
	
	//A + B = C
	
	double** mat_A = NULL;
	double** mat_B = NULL;
	double** mat_C = NULL;
	
	int lin_A, col_A, lin_B, col_B;
	
	printf("Qtd de linha e de colunas da matriz A: ");
	scanf("%d %d", &lin_A, &col_A);
	
	mat_A = alocaMatriz(mat_A, lin_A, col_A);
	
	lerMatriz(mat_A, lin_A, col_A, 'A');
	
	
//------------------------------------------------------------------------------------------------------
	
	printf("\n\n");
	
    printf("Qtd de linha e de colunas da matriz B: ");
	scanf("%d %d", &lin_B, &col_B);
	
	mat_B = alocaMatriz(mat_B, lin_B, col_B);
	
	lerMatriz(mat_B, lin_B, col_B, 'B');
	
	
//------------------------------------------------------------------------------------------------------

    if(lin_A == lin_B && col_A == col_B){
    	printf("\n\nCalculando a soma das matrizes...\n\n");
    	
    	imprimirMatriz(mat_A, lin_A, col_A, 'A');
    	
    	imprimirMatriz(mat_B, lin_B, col_B, 'B');
    	
    	mat_C = alocaMatriz(mat_C, lin_A, col_A);
    	
    	mat_C = somarMatrizes(mat_C, mat_A, mat_B, lin_A, col_A);
    	
    	imprimirMatriz(mat_C, lin_A, col_A, 'C');
    	
    	liberaMatriz(mat_A, mat_B, mat_C, lin_A);
    	
	}
	
	else{
		printf("\nNão é possivel calcular a soma, matrizes de tamanhos diferentes!\n");
	}

	
	
}
