#include "stdio.h"

typedef struct aluno{
	char nome[30];
	char matricula[30];
	char curso[15];
}Aluno;

int main(){
	
	Aluno turma[3];
	
	for(int i=0; i<3; i++){
		printf("NOME ALUNO %d: ", i+1);
    	scanf("%s", &turma[i].nome);
    	
    	printf("MATRICULA: ");
    	scanf("%s", &turma[i].matricula);
    	
    	printf("CURSO: ");
    	scanf("%s", &turma[i].curso);
    	
    	printf("\n");
    	
	}
	
	for(int i=0; i<3; i++){
		printf("%s / ", turma[i].nome);
		printf("%s / ", turma[i].matricula);
		printf("%s\n", turma[i].curso);
	}

}
