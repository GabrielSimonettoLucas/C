
#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

//----------------------------------------------
//----------------------------------------------

typedef struct NoLista* PtrNoLista;
typedef struct NoLista {
    int chave;
    char nome[20];
    char sexo;
    int idade;
    double peso, altura;
    char telefone[20];
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int qtdeElementos;
} ListaOrdenada;

//----------------------------------------------
//----------------------------------------------

void iniciaListaOrdenada(ListaOrdenada *l) {
    l->inicio = NULL;
    l->qtdeElementos = 0;
}
//----------------------------------------------
//----------------------------------------------
bool estaVaziaListaOrdenada(ListaOrdenada *lista) {
    return(lista->inicio == NULL);
}
//----------------------------------------------
//----------------------------------------------
int tamanhoListaOrdenada(ListaOrdenada *lista) {
    return(lista->qtdeElementos);
}
//----------------------------------------------
//----------------------------------------------
void imprimeListaOrdenada(ListaOrdenada *lista, FILE* saida) { //Imprime os dados em ordem crecente de ID
    PtrNoLista aux;
    for(aux = lista->inicio; aux!= NULL; aux=aux->proximo) {
        fprintf(saida,"{%d,%s,%c,%d,%.2lf,%.2lf,%s}\n", aux->chave, aux->nome, aux->sexo, aux->idade, aux->peso, aux->altura, aux->telefone);
    }
}
//----------------------------------------------
//----------------------------------------------
void imprimeListaOrdenadainv(ListaOrdenada *lista, FILE* saida) { //Imprime os dados em ordem decrecente de ID
    PtrNoLista sent = lista->inicio->anterior;
    int n;
    for(n=0; n<lista->qtdeElementos; n++) {
        fprintf(saida,"{%d,%s,%c,%d,%.2lf,%.2lf,%s}\n", sent->chave, sent->nome, sent->sexo, sent->idade, sent->peso, sent->altura, sent->telefone);
        sent=sent->anterior;
    }  
}
//----------------------------------------------
//----------------------------------------------
void inserirListaOrdenada(ListaOrdenada *lista, int valor, char nome[20], char sexo, int idade, double peso, double altura, char telefone[20]) {  //Insere os valores e conecta o no de lista com o restante da lista
    PtrNoLista novo = malloc(sizeof(NoLista));
    novo->chave = valor;
    strcpy(novo->nome, nome);
    novo->sexo=sexo;
    novo->idade=idade;
    novo->peso=peso;
    novo->altura=altura;
    strcpy(novo->telefone, telefone);

    if(estaVaziaListaOrdenada(lista)) {
        PtrNoLista sentinela = malloc(sizeof(NoLista));
        lista->inicio = novo;
        lista->inicio->anterior = sentinela;
        lista->inicio->proximo = NULL;
        sentinela->proximo=lista->inicio;
        sentinela->chave = -2;

    } else if(valor < lista->inicio->chave) {
        novo->anterior=lista->inicio->anterior;
        novo->proximo=lista->inicio;
        lista->inicio->anterior=novo;
        lista->inicio = novo;
        PtrNoLista aux = lista->inicio;
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
        lista->inicio->anterior=aux;
    } else {
    PtrNoLista aux = lista->inicio;
    PtrNoLista aux3 = lista->inicio;

        while(aux->proximo != NULL && valor > aux->proximo->chave) {
            aux = aux->proximo;
        }
        while(aux3->proximo != NULL) {
            aux3 = aux3->proximo;
        }
        if(valor>=aux3->chave){
            novo->proximo=NULL;
            novo->anterior=aux3;
            aux3->proximo=novo;
        }else{
            novo->proximo = aux->proximo;
            novo->anterior = aux;
            aux->proximo = novo;
            novo->proximo->anterior=novo;            
        }
        PtrNoLista aux2 = lista->inicio;
            while(aux2->proximo != NULL) {
                aux2 = aux2->proximo;
            }
        lista->inicio->anterior=aux2;
    }
    lista->qtdeElementos++;
}
//----------------------------------------------
//----------------------------------------------
void pesquisa(ListaOrdenada *lista, int pesquisa, FILE* saida) { //Percorre a lista do inicio ao fim até achar a chave correspondente com a inserida para a pesquisa
        PtrNoLista aux = lista->inicio;
        while(aux->proximo != NULL) {
            if(aux->chave == pesquisa){
                fprintf(saida, "{%d,%s,%c,%d,%.2lf,%.2lf,%s}\n", aux->chave, aux->nome, aux->sexo, aux->idade, aux->peso, aux->altura, aux->telefone);
                return;
            }
        aux = aux->proximo;
        }
        fprintf(saida,"Elemento nao encontrado!");
}
//----------------------------------------------
//----------------------------------------------
void entradavalida(char teste, FILE* saida){ //Verifica se as entradas de teste são validas ou não
    if(teste=='}'){
        fprintf(saida, "Arquivo Invalido!");
        exit(0);
    }
}
//----------------------------------------------
//----------------------------------------------
int main(int argc, const char * argv[]) {
    
    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = fopen(argv[2], "w");
    
    ListaOrdenada lista;
    int chave;
    char nome[20];
    char sexo;
    int idade;
    double peso, altura;
    char telefone[20];
    char teste;
    int retorno;
    int pesquisar;

    if (entrada==NULL||saida==NULL){
      fprintf(saida,"Falha em abrir um dos arquivos");
      }

    iniciaListaOrdenada(&lista);

    while(retorno!=EOF){
        retorno=fscanf(entrada," %c", &teste);
        if(retorno!=EOF){
            if(teste=='{'){
                fscanf(entrada," %d", &chave);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %[^,]s", nome);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %c", &sexo);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %d", &idade);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %lf", &peso);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %lf", &altura);
                fscanf(entrada," %c", &teste);
                entradavalida(teste, saida);
                fscanf(entrada," %[^}]s", telefone);
                fscanf(entrada," %c", &teste);
                inserirListaOrdenada(&lista, chave, nome, sexo, idade, peso, altura, telefone);
 
            }else if(teste=='1'){
                imprimeListaOrdenada(&lista, saida);
            }else if(teste=='2'){
                imprimeListaOrdenadainv(&lista, saida);
            }else if(teste=='3'){
                fscanf(entrada," %d", &pesquisar);
                pesquisa(&lista, pesquisar, saida);
            }else{
                fprintf(saida, "Arquivo Invalido!");
                exit(0);
            }

        }
}
    return 0;
}

//----------------------------------------------
//----------------------------------------------