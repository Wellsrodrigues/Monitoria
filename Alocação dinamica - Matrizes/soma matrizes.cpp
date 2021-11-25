#include "stdio.h"

//EXEMPLO COM MATRIZES ESTATICAS

int main(){
	
	int A[2][3] = {3, 6, 7,
	              4, 6, 8};
	                 
    int B[2][3] = {1, 1, 1,
	               1, 1, 1};
	
	int C[2][3]; //SOMA DE MATRIZES: AMBAS TEM QUE TER O MESMO TAMANHO, GERANDO OUTRA MATRIZ RESULTADO DE MESMO TAMANHO
	
	
//	C[0][0] = A[0][0] + B[0][0]; //SOMAMOS OS ELEMENTOS NAS MESMAS POSIÇOES E ADCIONAMOS A NOVA MATRIZ

	for(int i=0; i<2; i++){
    		for(int j=0; j<3; j++){
    	       C[i][j] = A[i][j] + B[i][j]; //CRIANDO MATRIZ ESTATICA COM SOMATORIO
     	}
     }


       printf("\nMatriz C:\n");
    	for(int i=0; i<2; i++){
    		for(int j=0; j<3; j++){
    	     printf("%d ", C[i][j]);
     	}
     	printf("\n");
    }
    
}
