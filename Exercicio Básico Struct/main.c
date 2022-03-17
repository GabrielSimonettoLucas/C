#include <stdio.h>
#include <stdlib.h>



//------------------------------------------------------------------------
// declarando as estruturas.
typedef struct enderecoo {
	char rua[64];
	char cidade[64];
	char estado[64];
	int numero;
}endereco;

typedef struct cliente {
	int id;
	char nome[64];
	char telefone[64];
	endereco numb;
}cliente;

//------------------------------------------------------------------------

//funcao usada para ler os dados dos clientes.

void ler_cliente(cliente *pessoas, int n){
	int a=0;
	for(a=0;a<n;a++){
		pessoas[a].id=0;
		printf("Informe o id do cliente.\n");
		scanf(" %d", &pessoas[a].id);
		printf("Informe o nome do cliente.\n");
		scanf(" %[^\n]s", pessoas[a].nome);
		printf("Informe a rua em que o cliente mora.\n");
		scanf(" %[^\n]s", pessoas[a].numb.rua);
		printf("Informe o estado onde o cliente vive.\n");
		scanf(" %[^\n]s", pessoas[a].numb.estado);
		printf("Informe a cidade do cliente.\n");
		scanf(" %[^\n]s", pessoas[a].numb.cidade);
		printf("Informe o numero da residencia do cliente.\n");
		scanf(" %d", &pessoas[a].numb.numero);
		printf("Informe o numero de telefone do cliente.\n");
		scanf(" %[^\n]s", pessoas[a].telefone);
	}
}

//------------------------------------------------------------------------

//funcao usada para pesquisar os dados dos clientes pelo seu ID.

void buscar_cliente(cliente *pessoas, int n){
	int a=0;
	int id=0;
	int controle_while;
	int falha;


	do{
	printf("Informe o ID do cliente.\n\n");
	scanf(" %d", &id);
	
	for(a=0;a<n;a++){
		if(id==pessoas[a].id){
			
			printf("%d - %s\n", pessoas[a].id, pessoas[a].nome);
			printf("%s, %d\n", pessoas[a].numb.rua, pessoas[a].numb.numero);
			printf("%s - %s\n", pessoas[a].numb.cidade, pessoas[a].numb.estado);
			printf("Tell: %s\n\n", pessoas[a].telefone);
		}else{
			falha++;
		}
	}

	if(falha==n){
		printf("ID nao encontrado.\n\n");
	}

	printf("Oque dejas realizar a seguir ?\n1 - Sair da area de pesquisa.\n2 - Pesquisar novamente.\n\n");
	scanf (" %d", &controle_while);

	} while (controle_while!=1);
}

//------------------------------------------------------------------------
//chama outras funcoes e recebe do usuário quantos clientes serao registrados.
int main(int argc, char *argv[]) {
	
    int quantia, selecao, terminar_while;

    printf("Informe quantas pessoas voce deseja salvar:\n\n");
    scanf(" %d", &quantia);
    cliente pessoas[quantia];

    do{
    printf("Que acao deseja realizar?\n1 - Registrar clientes.\n2 - Pesquisar clientes.\n\n");
    scanf(" %d", &selecao);

            switch (selecao){
    
            case 1:
                ler_cliente(pessoas, quantia);
                printf("Oque desejas fazer a seguir?\n1 - Encerar o programa\n2 - Voltar ao menu de selecao.\n\n");
                scanf(" %d", &terminar_while);
                break;

            case 2:
                buscar_cliente(pessoas, quantia);
                printf("Oque desejas fazer a seguir?\n1 - Encerar o programa\n2 - Voltar ao menu de selecao.\n\n");
                scanf(" %d", &terminar_while);
                break;
               
            default:
            printf("Opcao invalida.\n\n");
                break;
            }

    }while (terminar_while!=1);
    
	
	return 0;
}

//------------------------------------------------------------------------