//----------------------------------------------
//----------------------------------------------

#include <stdio.h>
#include <stdbool.h> // true/false
#include <stdlib.h>  // free, malloc, sizeof

//----------------------------------------------
//----------------------------------------------


typedef struct NoLista* PtrNoLista;

typedef struct NoLista {
    int chave;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int qtdeElementos;
} Lista;

void iniciaListaOrdenada(Lista *lista) {
    lista->inicio = NULL;
    lista->qtdeElementos = 0;
}

bool estaVaziaListaOrdenada(Lista *lista) {
    return(lista->inicio == NULL);
}

int tamanhoListaOrdenada(Lista *lista) {
    return(lista->qtdeElementos);
}

void imprimeListaOrdenada(Lista *lista) {
    printf("Lista = [");
    PtrNoLista aux;
    for(aux = lista->inicio; aux!= NULL; aux=aux->proximo) {
        printf("%d ", aux->chave);
    }
    printf("]\n");
}

void inserirListaOrdenada(Lista *lista, int valor) {
    PtrNoLista novo = malloc(sizeof(NoLista));
    novo->chave = valor;

    if(estaVaziaListaOrdenada(lista)) {
        lista->inicio = novo;
        novo->proximo = NULL;
    } else if(valor < lista->inicio->chave) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    } else {
    PtrNoLista aux = lista->inicio;
        while(aux->proximo != NULL && valor > aux->proximo->chave) {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    lista->qtdeElementos++;
}

//----------------------------------------------
//----------------------------------------------


bool removerListaOrdenada(Lista *lista, int valor) {

    PtrNoLista rm;
    if(estaVaziaListaOrdenada(lista) || valor < lista->inicio->chave) {
        return false;
    }

    if(valor == lista->inicio->chave) {
        rm = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(rm);
        lista->qtdeElementos--;
        return true;
    }

    PtrNoLista aux = lista->inicio;
    while(aux->proximo != NULL && valor > aux->proximo->chave) {
        aux = aux->proximo;
    }

    if(aux->proximo == NULL || aux->proximo->chave > valor) {
        return false;
    }
    rm = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(rm);
    lista->qtdeElementos--;
    return true;
}

void iniciavetor(int n, int* v){
    for(int a=0;a<n;a++){
        v[a]=NULL;
    }
}
void lervetor(int n, int* v){
    for(int a=0;a<n;a++){
        scanf(" %d", &v[a]);
    }
}
void imprimevetor(int n, int* v){
    for(int a=0;a<n;a++){
        printf("%d ", v[a]);
    }
    printf("\n");
}

Lista* constroi(int n, int*v){
    Lista *listaordenada;
    iniciaListaOrdenada(listaordenada);
    for(int a=0;a<n;a++){
        inserirListaOrdenada(listaordenada, v[a]);
    }
    return(listaordenada);
}
//----------------------------------------------
//----------------------------------------------

int main(int argc, const char * argv[]) {


    int n=2;
    int vetor[2];
    iniciavetor(n, vetor);
    lervetor(n, vetor);
    imprimevetor(n, vetor);
    Lista *retorno;
    retorno = constroi(n, vetor);
    imprimeListaOrdenada(retorno);
    //printf("%d %d", retorno->inicio->chave, retorno->inicio->proximo->chave);
    return 0;
}

//----------------------------------------------
//----------------------------------------------