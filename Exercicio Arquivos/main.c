
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
//---------------------------------------------------------------
void cadastrar_produto(void);
void mostrar_produtos(void);
void mostrar_estoque(void);
void apagar_stoque(void);
//---------------------------------------------------------------

//Declarando a struct dos produtos

typedef struct mercadorias{

	int cod;
	char desc[45];
	int quant;
}produtos;
//---------------------------------------------------------------
//Funcao que recebe da entrada padrao informacoes dos produtos
void cadastrar_produto(){
	FILE *arq;
	arq = fopen ("produtos.bin", "ab");
	produtos merch;
	printf("Insira o codigo do produto\n");
	scanf(" %d", &merch.cod);
	printf("insira a descricao do produto\n");
	scanf(" %[^\n]s", merch.desc);
	printf("Informe a quantos deste produto esta disponivel\n");
	scanf(" %d", &merch.quant);
	fwrite (&merch,sizeof(struct mercadorias),1,arq);
	fclose(arq);
}
//---------------------------------------------------------------
//funcao utilizada para exibir informacoes de todos os produtos
void mostrar_produtos(){
	FILE *arq;
	arq = fopen ("produtos.bin", "rb");
	produtos mostrar;
	char teste;

	teste = fgetc(arq);
	if (teste != EOF){

		fseek(arq,0*sizeof(char), SEEK_SET);

		while(teste != EOF){
		fread (&mostrar, sizeof(struct mercadorias),1,arq);
		printf("\ncodigo: %d\n", mostrar.cod);
		printf("descricao: %s\n", mostrar.desc);
		printf("quantidade: %d\n", mostrar.quant);
		printf("\n");
		teste = fgetc(arq);
		fseek(arq,1*sizeof(struct mercadorias), SEEK_SET);	
	}
    }else{
		printf("Nenhum produto registrado.\n");
	}
	printf("Pressione qualquer tecla para continuar\n");
	system("pause");
	fclose(arq);
}
//---------------------------------------------------------------
//funcao utilizada para pesquisar o estoque de alguma produto especifico atraves do seu ID
void mostrar_estoque(){
	FILE *arq;
	arq = fopen ("produtos.bin", "rb");
	produtos mostrar;
	int pesquisar;
	int retorno=0;
	printf("Informe o codigo do produto\n");
	scanf(" %d", &pesquisar);
	while(retorno!=9){
		fread (&mostrar, sizeof(struct mercadorias),1,arq);
		if(pesquisar==mostrar.cod){
			printf("%d\n", mostrar.quant);
			break;
		}else{
			fseek(arq,1*sizeof(struct mercadorias), SEEK_SET);
		}
	}
	printf("Pressione qualquer tecla para continuar\n");
	system("pause");
	fclose(arq);
}
//---------------------------------------------------------------
//funcao para apagar o conteudo da pasta produtos.bin
	void apagar_stoque(){
		FILE *arq;
		arq = fopen ("produtos.bin", "wb");
		fclose(arq);
	}
//---------------------------------------------------------------

int main() {
	
	int opcao;
	do {
    	system("cls");
		printf("MENU:\n");
    	printf("1 - Cadastrar produto\n");
    	printf("2 - Mostrar as descricoes de todos produtos\n");
    	printf("3 - Mostrar a quantidade de estoque de um produto\n");
		printf("4 - Apagar o estoque\n");
    	printf("0 - Encerrar o Programa\n");
    	printf("-----------------------------\n");
    	printf("Informe a opcao desejada:\n");
    	do {
      		scanf("%d", &opcao);
      		if((opcao < 0) || (opcao > 4))
      			printf("Opcao invalida! Tente novamente.\n");
    	} while ((opcao < 0) || (opcao > 4));
    	switch (opcao) {
    		case 1: cadastrar_produto(); break;
      		case 2: mostrar_produtos(); break;
      		case 3: mostrar_estoque(); break;
			case 4: apagar_stoque(); break;  
    	}
  	} while (opcao != 0);
}
