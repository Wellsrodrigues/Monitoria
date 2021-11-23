#include "stdio.h"
#include "stdlib.h"

int main(){
	
	FILE* file;
	int num1, num2;
	
	/*
	file = fopen("arquivo.txt", "w"); //escreve no arquivo
	
	fprintf(file, "Escrevendo no Arquivo"); //escreve no arquivo
    */
    
	//file = fopen("arquivo.txt", "a"); //para anexar informacoes
	
    file = fopen("arquivo.txt", "r"); //abre o arquivo para leituras
   
    if(file == NULL){
    	printf("O arquivo nao pode ser aberto\n");
    	exit(1);
	}
	
	fscanf(file, "%d %d", &num1, &num2); //capturando dados do meu arquivo para as minhas variaveis
	
    printf("Os numeros salvos no arquivo sao: %d e %d\n", num1, num2); //so imprime a 1° linha
	
    fclose(file); //fechando arquivo
    
    
	return 0;
}
