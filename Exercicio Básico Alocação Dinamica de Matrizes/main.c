#include <stdio.h>
#include <stdlib.h>

//Programa utilizado para alocar dinamicamente uma matriz quadrada.

void limpar (int **matriz, int tamanho){

    //libarar a memoria onde a matriz foi alocada.

	int contagem;
	for(contagem=0;contagem<tamanho;contagem++){
		free(matriz[contagem]);
	}
	free(matriz);
}

void imprimir(int **matriz, int tamanho){

    //Imprimindo a matriz alocada.

	int contagem1, contagem2;
	for(contagem1=0;contagem1<tamanho;contagem1++){
		for(contagem2=0;contagem2<tamanho;contagem2++){
			printf("%d ", matriz[contagem1][contagem2]);
		}
		printf("\n");
	}
}

void preencher (int **matriz, int tamanho){

    //Preenchendo a matriz alocada com valores quaisquer.

	int contagem1, contagem2;
	
	for(contagem1=0;contagem1<tamanho;contagem1++){
		for(contagem2=0;contagem2<tamanho;contagem2++){
			matriz[contagem1][contagem2]=contagem1+contagem2*2;
		}
	}
}

int** criar (int tamanho){
	int **matriz, contagem;
	//Funcao utilizada para alocar dinamicamente espaço de memoria para criar uma matriz quadrada.
	matriz = (int **) calloc (tamanho, sizeof (int**));
	for(contagem=0;contagem<tamanho;contagem++){
		matriz[contagem] = calloc (tamanho, sizeof(int));
	}
	
	return matriz;
	
} 

int main(int argc, char *argv[]) {
	
	int tamanho, **matriz;
	printf("Insira o tamanho da matriz:\n");
	scanf(" %d", &tamanho);

	//Chamando as diferentes funcoes.

	matriz = criar(tamanho);
	preencher (matriz, tamanho);
	imprimir (matriz, tamanho);
	limpar (matriz, tamanho);
	
	return 0;
}
