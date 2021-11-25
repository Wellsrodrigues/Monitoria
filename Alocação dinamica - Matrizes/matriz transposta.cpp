#include "stdio.h"


//EXEMPLO COM MATRIZES ESTATICAS

int main(){
	
	int mat[2][3] = {3, 6, 7,
	                 4, 6, 8};
	                 
	printf("\nMatriz Normal:\n");
	for(int i=0; i<2; i++){
    	for(int j=0; j<3; j++){
    	    printf("%d ", mat[i][j]);
     	}
     	printf("\n");
	}
	                 
    int transposta[3][2]; //O QUE É LINHA VIRA COLUNA E O QUE COLUNA VIRA LINHA NA TRANSP.
    
    for(int i=0; i<2; i++){
    	for(int j=0; j<3; j++){
    	     transposta[j][i] = mat[i][j]; //criando transposta
     	}
	}
	
	printf("\nMatriz Transposta:\n");
    	for(int i=0; i<3; i++){
    		for(int j=0; j<2; j++){
    	     printf("%d ", transposta[i][j]);
     	}
     	printf("\n");
    }
}
