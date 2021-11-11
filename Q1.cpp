#include <stdio.h>

/*Faça um programa que receba o nome e o sexo de uma pessoa, se for do sexo feminino, o
programa irá dizer Bem-vinda + nome da pessoa, se for masculino, Bem-vindo + nome da
pessoa. (IF-ELSE)*/

int main(void) { 
    char nome[50]; 
     char sexo; 
    
    printf("Digite seu nome: "); 
    scanf("%s", &nome);   
          
    printf("Informe sexo: ");   
    scanf("%s", &sexo); 
            
    if (sexo == 'F' || sexo == 'f'){   
     printf("Bem-vinda, %s\n", nome); 
   }  
   else if(sexo == 'M' || sexo == 'm'){   
       printf("Bem-vindo, %s", nome);  
   }
   else{
   	  printf("Sexo incorreto");
   }
}
