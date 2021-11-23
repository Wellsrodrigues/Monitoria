#include "stdio.h"
#include "stdlib.h"


int main(){
	int **mat;
    int i, j, LIN, COL;
    
    printf("Numero de linhas e colunas da matriz dinamica: ");
    scanf("%d %d", &LIN, &COL);

// aloca um vetor de ponteiros para linhas
    mat = (int**)malloc (LIN * sizeof (int));
    

// aloca um vetor para cada uma das linhas 
for (i=0; i < LIN; i++){
	 mat[i] = (int*) malloc (COL * sizeof (int));
}

// percorre a matriz para inserir valores
for (i=0; i < LIN; i++){
   for (j=0; j < COL; j++){
   	  printf("Valor da matriz: ");
   	  scanf("%d", &mat[i][j]); // acesso com sintaxe mais simples
    }
}

//imprimindo minha matriz
printf("\n\nMatriz criada:\n\n");
for(int i=0; i < LIN; i++){
   for (int j=0; j < COL; j++){
        printf("%d ", mat[i][j]);
   }
   printf("\n");
}

// libera a memória da matriz
for (i=0; i < LIN; i++){
	free (mat[i]); //liberando vetor de linhas
}
   free (mat) ;  //liberando vetor de colunas
   
}

