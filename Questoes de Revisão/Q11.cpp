#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int*);

int n;
int main(){

  int *pp = NULL;

  printf("Informe o numero de componentes do vetor\n");
  scanf("%d", &n);

 
   pp = (int *)malloc(n*sizeof(int));
   
   if(pp == NULL){

      printf("Erro: Memória Insuficiente!\n");
      exit(1);
   }
   
   preenche_vetor(pp);
   
   printf("\nValores do vetor dinamico: ");
  
  for (int i = 0;i < n; i++){
    printf("%d ",pp[i]);
  }
 
   if(pp != NULL){
     free(pp);
     pp = NULL;
     printf("\nExecucao com Sucesso!\n");
   }

return 0;

}

void preenche_vetor(int *p){
	for (int i = 0; i < n; i++) {
    printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    scanf("%d",&p[i]);
  }
}

