#include <stdio.h>

int main(void)
{
    int *ponteiro, **ponteiroDoPonteiro, valor;
    valor = 50;
    ponteiro = &valor; //ponteiro aponta para a variavel inteira
    ponteiroDoPonteiro = &ponteiro; //aponta para o ponteiro
    
    printf("\nValor de ponteiroDoPonteiro: %p\n", ponteiroDoPonteiro);
	printf("Endereço de memoria de ponteiro: %p\n", &ponteiro);
	printf("Valor de ponteiro: %p\n", ponteiro);
	printf("Endereco de memoria de valor: %p\n", &valor);
	printf("Valor: %d", valor);
	
    return 0;
}
