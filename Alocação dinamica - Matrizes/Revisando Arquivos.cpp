#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE* file;
	char texto[50];
	
	/*
	file = fopen("arquivo.txt", "w"); //escreve no arquivo
	
	fprintf(file, "Escrevendo no Arquivo"); //escreve no arquivo
    */
    
    //file = fopen("arquivo.txt", "r"); //lendo arquivo
    
	file = fopen("arquivo.txt", "a"); //anexar informacao
   
    if(file == NULL){
    	printf("O arquivo nao pode ser aberto\n");
    	exit(1);
	}
  
	//fscanf(file, "%s", texto); //retorna a string ate o espaco
	
	fprintf(file, "novamente\n");
	
	char nome[] = "joao\n";
	
	fputs(nome, file);
	
	fgets(texto, 50, file); //retorna a  string completa
	
	/*
	while(fgets(texto, 50, file) != NULL){ //lendo varias frases de uma vez
		printf("%s", texto);
	}
	*/
	
    printf("%s", texto); //so imprime a 1° linha
	
    fclose(file); //fechando arquivo
    
    
	return 0;
}
