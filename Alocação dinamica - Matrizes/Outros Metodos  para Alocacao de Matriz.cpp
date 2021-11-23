#include "stdio.h"
#include "stdlib.h"
#define LIN 4
#define COL 6


void alocacaoUnica(){
	int *mat;

// aloca um vetor com todos os elementos da matriz
    mat = (int *) malloc (LIN * COL * sizeof (int));

// percorre a matriz
for (int i=0; i < LIN; i++){
   for (int j=0; j < COL; j++){
      mat[(i*COL) + j] = 0 ; // calcula a posição de cada elemento
  }
}

//imprimindo
for(int i=0; i < LIN; i++){
   for (int j=0; j < COL; j++){
        printf("%d ", mat[(i*COL) + j]);
   }
   printf("\n");
}

// libera a memória alocada para a matriz
    free(mat);

}

//----------------------------------------------------------------------------------------------------------------

void alocaEmLinhas(){
	int **mat ;
    int i, j ;

// aloca um vetor de LIN ponteiros para linhas
    mat = (int**)malloc (LIN * sizeof (int));

// aloca cada uma das linhas (vetores de COL inteiros)
for (i=0; i < LIN; i++){
	 mat[i] = (int*) malloc (COL * sizeof (int));
}

// percorre a matriz
for (i=0; i < LIN; i++){
   for (j=0; j < COL; j++){
      mat[i][j] = 1 ;        // acesso com sintaxe mais simples
    }
}

//imprimindo
for(int i=0; i < LIN; i++){
   for (int j=0; j < COL; j++){
        printf("%d ", mat[i][j]);
   }
   printf("\n");
}

// libera a memória da matriz
for (i=0; i < LIN; i++){
	free (mat[i]) ;
}
free (mat) ; 
}


//----------------------------------------------------------------------------------------------------------------

void linhasContiguas(){
 int **mat ;
int i, j ;

// aloca um vetor de LIN ponteiros para linhas
mat = (int**)malloc (LIN * sizeof (int));

// aloca um vetor com todos os elementos da matriz
mat[0] = (int*)malloc (LIN * COL * sizeof (int)) ;

// ajusta os demais ponteiros de linhas (i > 0)
for (i=1; i < LIN; i++){
	mat[i] = mat[0] + i * COL ;
}

// percorre a matriz
for (i=0; i < LIN; i++){
   for (j=0; j < COL; j++){
      mat[i][j] = 2 ;
  }
}
      
//imprimindo
for(int i=0; i < LIN; i++){
   for (int j=0; j < COL; j++){
        printf("%d ", mat[i][j]);
   }
   printf("\n");
}

// libera a memória da matriz
free (mat[0]) ;
free (mat) ;
}


//----------------------------------------------------------------------------------------------------------------


int main(){
    
    alocacaoUnica();
    printf("\n");
    
    alocaEmLinhas();
    printf("\n");
    
    linhasContiguas();

}
