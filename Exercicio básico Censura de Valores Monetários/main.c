#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
	//Programa feito para identificar e censurar valores monetarios.
int main(void){
	//-----------------------------
    //Declaracao de todas as variaveis.
	char frase[100];
	int tamanhofrase, contagem;
	//-----------------------------	
    //Recebimento de valores pela entrada padrão.

    printf("Digite uma frase contendo algum valor monetário, como por exemplo: 'No dia 23 do 02 lucramos R$30000.00.'\n");
	scanf(" %[^\n]s", frase);
	tamanhofrase = strlen(frase);

	//-----------------------------
    //Processo de itendificação e cencura de valores monetários.	 
	for (contagem=0; contagem<=tamanhofrase; contagem++){
		if (frase[contagem]=='$'){
			contagem++;
			for(; frase[contagem]!=32; contagem++){
				if ((frase[contagem]>=48 && frase[contagem]<=57) || frase[contagem]=='.'|| frase[contagem]==','){
					frase[contagem]='*';
				}
			}
		}
	}
	//-----------------------------    
	printf("%s", frase);
	setlocale(LC_ALL, "Portuguese");
}