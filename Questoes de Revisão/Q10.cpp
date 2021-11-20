#include "stdio.h"


int main(){
	int vet[5] = {1, 3, 6, 7, 4};
	int *pont;
	
	pont = vet;
	
	for(int i=0; i<5; i++){
    	*(pont+i) = vet[i] + 1;
    	printf("%d ", vet[i]);
    }

}
