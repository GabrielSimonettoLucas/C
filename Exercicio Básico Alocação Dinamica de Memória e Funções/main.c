#include <stdio.h>
#include <stdlib.h>

//--------------------
//Programa simples para criar um vetor utilizando alocacao dinamica de memoria usando funcoes separadas.
//--------------------

void imprimir (int *vetor, int tamanho){
    //funcao utilizada apenas para imprimir os valores contidos no vetor.
	int a;
	for(a=0;a<tamanho;a++){
		printf("%d ", vetor[a]);
	}
}

void preencher (int *vetor, int tamanho){
    //funcao utilizada para preencher o vetor, usado apenas como exemplo.
    int a;
	for(a=0;a<tamanho;a++){
		vetor[a]=a+1;
	}
}

int* alocar (int tamanho){
    //Funcao utilizada para alocar dinamicamente o vetor de acordo com a quantia de caracteres insirida pelo usuário.
	int *aloc;
	aloc = (int*) calloc (tamanho, sizeof(int));
	
	if(aloc==NULL){
		printf("Falha ao alocar o vetor");
	}else{
		return aloc;
	}
}

int main(int argc, char *argv[]) {
	int tamanho, *vetor;
    printf("Insira o tamanho do vetor a ser alocado:\n");
	scanf(" %d", &tamanho);
	
    //------------
    //chamando as diferentes funcoes.

	vetor = alocar (tamanho);
	preencher (vetor, tamanho);
	imprimir (vetor, tamanho);
	//------------
	return 0;
}