#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Progrma simples para calcular a media de peso, separando por faixa etaria.

int main() {
	setlocale(LC_ALL, "Portuguese");
	//---------------------------------

    //Declaracao de todas as variaveis;

	float peso, media1, media2, media3, media4;
	int idade, contador, quantidade, denominador1=0, denominador2=0, denominador3=0, denominador4=0;
	//---------------------------------

	printf("Informe a quantia de pessoas para realizar a média:");
	scanf(" %d", &quantidade);
	printf("Envie a idade e o peso de cada pessoa\n");
	
    //--------------------------------

    //FOR para a divisao por faixa etaria e soma das medidas.

	for(contador=0; contador<quantidade; contador++){
		idade=0;
		scanf(" %d", &idade);
		scanf(" %f", &peso);
		
		if (peso>0){
		
			if(idade>=1 && idade<=10){
				denominador1++;
				media1+=peso;
			}else if(idade>=11 && idade<=20){
				denominador2++;
				media2+=peso;
			}else if(idade>=21 && idade<=30){
				denominador3++;
				media3+=peso;
			}else if(idade>=31){
				denominador4++;
				media4+=peso;
			}else{
				printf("Entrada Invalida!\n");
				contador--;
			}
		}else{
			printf("Entrada Invalida!\n");
			contador--;
		}
	}
	
	//--------------------------------
	
    //--------------------------------

    //Resultado das medias e impressao das faixas etarias relevantes.

	if (denominador1!=0){
		printf("1 a 10 anos: %.2f\n", media1/denominador1);
	}
	if (denominador2!=0){
		printf("11 a 20 anos: %.2f\n", media2/denominador2);
	}
	if (denominador3!=0){
		printf("21 a 30 anos: %.2f\n", media3/denominador3);
	}
	if (denominador4!=0){
		printf("31 anos ou mais: %.2f\n", media4/denominador4);
	}
	
	return 0;

    //--------------------------------

}
