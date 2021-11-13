#include "stdio.h"
#include <stdlib.h>

int main(){
	int n; float soma = 0;
	float *notas = NULL;


  printf("Informe a qtde de alunos: \n");
  scanf("%d", &n);

 
   notas = (float *)malloc(n*sizeof(float));
   
   if(notas == NULL){

      printf("Erro: Memória Insuficiente!\n");
      exit(1);
   }
   
  
  	for (int i = 0; i < n; i++) {
    printf("\nDigite a nota do aluno %d: ", i+1);
    scanf("%f",&notas[i]);
    soma += *(notas+i);
  }
  
  	printf("\nMedia das notas: %.2f\n", soma/n);

 	
 
   if(notas != NULL){
     free(notas);
     notas = NULL;
     printf("\nExecucao com Sucesso!\n");
   }

 return 0;
}
