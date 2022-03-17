#include <stdio.h>
#include <stdlib.h>

//Programa feito para criar uma matriz 3x3, preencher até o numero 9, e transformar em 0 os numeros maiores do que o valor inserido.

void printMatriz(int matrizX, int matrizY, int matriz[matrizX][matrizY]){
    //imprime a matriz na saida padrao.
	int contagem, contagem1;
	for (contagem=0;contagem<matrizX;contagem++){
		for(contagem1=0;contagem1<matrizY;contagem1++){
			printf("%d ", matriz[contagem][contagem1]);
		}
		printf("\n");
	}
}

int processaMatriz(int matrizX, int matrizY, int valor, int matriz[matrizX][matrizY]){
    //identifica os elementos menores que o valor insirido pelo usuário.
	int contagem, contagem1, mud=0;
	for(contagem=0;contagem<matrizX;contagem++){
		for(contagem1=0;contagem1<matrizY;contagem1++){
			if(matriz[contagem][contagem1]>valor){
				matriz[contagem][contagem1]=0;
				mud++;
			}
		}
	}
	return mud;
}

int main() {
	
	int valor, alteracoes=0;
	int matriz[3][3];
    printf("Insira o valor maximo a ser citado na matriz:\n");
	scanf("%d",&valor);
	
	int contagem1, contagem2, preencher=1;
	//preenche os elementos da matriz com valores de 1 a 9.
	for (contagem1=0; contagem1<3; contagem1++){
		for (contagem2=0; contagem2<3; contagem2++){
			matriz[contagem1][contagem2] = preencher;
            preencher++;
		}
	}
	alteracoes = processaMatriz(3, 3, valor, matriz);
	printMatriz(3, 3, matriz);
	printf("Alteracoes=%d",alteracoes);

}