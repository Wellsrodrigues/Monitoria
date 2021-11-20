#include "stdio.h"

void percorre(int *p){
  int n = 0;
  
  do{
	*(p+n) = n;
	printf("%d ", *(p+n));
	n++;
  }while(n < 5);
  
}	
int main(){
	int vet[5], *pont;
	
	pont = vet;
	
	percorre(pont);

}
