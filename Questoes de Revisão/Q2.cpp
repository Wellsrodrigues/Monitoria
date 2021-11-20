#include "stdio.h"

int main(){
	
	float preco, qtd, gasto;
	
	printf("PRECO DA GASOLINA: ");
	scanf("%f", &preco);
	
	printf("QTD DE LITROS PARA ABASTECER: ");
	scanf("%f", &qtd);
	
	gasto = preco * qtd;
	
	printf("\n\nVALOR A SER PAGO: R$ %.2f\n", gasto);
	
}
