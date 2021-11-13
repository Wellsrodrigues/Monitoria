#include "stdio.h"
#include <stdlib.h>

int* uniao_vetores(int* v1, int* v2, int n1, int n2, int* qtd){
    *qtd = n1+n2;
    int i, j, k, q, i2=0, i3 =0;
    int *v3 = NULL;
    
     v3 = (int *)malloc(*qtd*sizeof(int));
     
     if(v3 == NULL){
        printf("Erro: Memória Insuficiente!\n");
        exit(1);
      }
     
    for(i=0; i<*qtd; i++){
        if(i<n1){
            v3[i] = v1[i2];
           i2++;
        }
        else{
            v3[i] = v2[i3];
           i3++;
        }
    }
    
    for(j=0;j<i-1;j++){   /*verifica numeros repetidos*/
        for(k=0;k<i-1;k++){
            if(k!=j){
                if(v3[j]==v3[k]){
                    v3[j]=0;   /*deleta numeros repetidos*/
                    
                }
            }
        }
    }
    for(j=0;j<i-1;j++){   /*coloca em ordem crescente*/
        for(int k=j+1;k<i;k++){
            if(v3[j]>v3[k]){
                q=v3[j];
                v3[j]=v3[k];
                v3[k]=q;
            }
        }
    }
    
    return v3;

}


int main(){
	
	int x1[5] = {1, 3, 5, 6, 7};
	int x2[5] = {1, 3, 4, 6, 8};
	int n3;
	
	int *p, *qtd;
	
	qtd = &n3;
	
	p = uniao_vetores(x1, x2, 5, 5, qtd);
	
	for(int i=0;i<*qtd; i++){
			printf("%d ", *(p++));
    }
    
    if(p != NULL){
     free(p);
     p = NULL;
     printf("\nExecucao com Sucesso!\n");
   }
}
