#include "stdio.h"
#include "stdlib.h"

//----------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------

int** abrirArquivo(char nome[]){
	int** matriz;
	int lin, col;
	
	FILE* arq = fopen(nome, "r");
	
    if(arq == NULL){
    	printf("Erro de Leitura");
    	exit(1);
	} 
	
	fscanf(arq,"%d %d",&lin,&col);
	
	printf("Linha: %d\nColuna: %d", lin, col);
	
    matriz = alocaMatriz(matriz, lin, col); //chamando a funcao que cria matriz dinamica
  
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      fscanf(arq,"%d",&matriz[i][j]); //armazenar valores do arquivo a matriz
    }
   }
   
   printf("\n\n");
   
   for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
        	printf("%d ", matriz[i][j]); //imprimindo minha matriz
    	}
    	printf("\n");
	}
      
  fclose(arq); //fechando arquivo
   
	return matriz;
}

//----------------------------------------------------------------------------------------------------------

int main(){
	FILE *arq;
	
	int** matriz;
    char nomeArq[] = "Matriz.txt";
    
    
    matriz = abrirArquivo(nomeArq);
    

}
