#include "stdio.h"
#include "stdlib.h"


int main(){
	
	int *idades = NULL; 
	int qtd, maior=0, menor=0;	
	
	printf("Qtde de Pessoas: ");
	scanf("%d", &qtd);
	
	idades = (int*)malloc(qtd*sizeof(int));
	
	if(idades == NULL){ 
		printf("Memoria insuficiente");
		exit(1); 
	}
	
	for(int i=0; i<qtd; i++){ 
		printf("\nIdade pessoa %d: ", i+1);
		scanf("%d", &idades[i]);
	}
	
	for(int i=0; i<qtd; i++){
		if(idades[i] > 18){
			maior++;
		}else{
			menor++;
		}
	}
	
	printf("\n\nHa %d maior(es) e %d menor(es) de idade\n", maior, menor);
	
	if(idades != NULL){
		free(idades);
		idades = NULL;
		printf("\nConcluido com sucesso\n");
	}
	

	return 0;
}
