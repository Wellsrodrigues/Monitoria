#include "stdio.h"

int soma_dobro(int A, int B){
	A = 2*A;
	B = 2*B;
	return (A+B);
}
	
int main(){
	int a, b, res;
	
	
	printf("VALOR 1: ");
	scanf("%d", &a);
	
	printf("\nVALOR 2: ");
	scanf("%d", &b);
	
	res = soma_dobro(a,b);
	
	printf("\n\nRESULTADO = %d\n", res);
}
