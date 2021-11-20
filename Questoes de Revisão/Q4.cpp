#include "stdio.h"

int main(){
	
	int num[5], maior=0, menor=0;
	
	for(int i=0; i<5; i++){
		
		scanf("%d", &num[i]);
		
		if(i == 0){
		maior = num[0];
		menor = num[0];
     	}
     	
		if(num[i] > maior){
			maior = num[i];
		}
		
		if(num[i] < menor){
			menor = num[i];
		}
	}
	
	printf("maior: %d\nmenor: %d\n", maior, menor);
	
}
