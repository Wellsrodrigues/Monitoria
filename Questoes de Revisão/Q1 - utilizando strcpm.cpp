#include <stdio.h>
#include <string.h>

/*Faça um programa que receba o nome e o sexo de uma pessoa, se for do sexo feminino, o
programa irá dizer Bem-vinda + nome da pessoa, se for masculino, Bem-vindo + nome da
pessoa. (IF-ELSE)*/

int main(void) { 
    char nome[50]; 
     char sexo[10]; 
    
    printf("Digite seu nome: "); 
    scanf("%s", &nome);   
          
    printf("Informe sexo: ");   
    scanf("%s", &sexo); 
    
            
    if (strcmp(sexo,"feminino") == 0 || strcmp(sexo,"FEMININO") == 0){   
     printf("Bem-vinda, %s\n", nome); 
   }  
   else if(strcmp(sexo,"MASCULINO") == 0 || strcmp(sexo,"masculino") == 0){   
       printf("Bem-vindo, %s", nome);  
   }
   else{
   	  printf("Sexo incorreto");
   }
}
