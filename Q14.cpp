#include "stdio.h"
#include "string.h"

//MINHA STRUCT ENDERECO
typedef struct endereco{
	char rua[10];
	int num;
	int cep;
}Endereco;

//MINHA STRUCT TELEFONE
typedef struct{
	int num;
	int ddd;
}Telefone;

//MINHA STRUCT DATA
typedef struct{
	int dia;
	int mes;
	int ano;
}Data;


//MINHA STRUCT COMPLETA, UTILIZANDO STRUCTS DENTRO DE STRUCT
typedef struct { 
	char nome[30];
	char email[30];
	Endereco endereco;
	Telefone telefone;
	Data data;
	char lembrete[30];
}Agenda;

// typedef serve para definir um tipo ou nome para referenciar a struct criada

main(){
	
	Agenda g1[5]; //vetor de struct

	for(int i=0; i<1; i++){ //lendo minha struct
		
		printf("SEU NOME: ");
		scanf("%s", &g1[i].nome); 
		
		printf("DIA DE NASCIMENTO: ");
		scanf("%d", &g1[i].data.dia); //usamos ponto final para acessar os atributos da struct
		
		printf("SEU CEP: ");
		scanf("%d", &g1[i].endereco.cep);
		
		printf("\n");
	}
	
	
	for(int i=0; i<1; i++){ //imprimindo minha struct
    	printf("\n\n%s nasceu dia %d e seu cep eh %d\n", g1[i].nome, g1[i].data.dia, g1[i].endereco.cep);
    }
    

}
