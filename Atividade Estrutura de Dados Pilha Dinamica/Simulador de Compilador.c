#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>  

int global=1;          //Variaveis globais para controle das STR TEMP 
int reservartemp=0;

typedef struct NoPilha* PtrNoPilha;
//===========================================================================================================================
struct NoPilha {
  char elemento;
  PtrNoPilha proximo; 
} NoPilha;
//===========================================================================================================================
typedef struct {
  PtrNoPilha topo;
  int qtde;
} PilhaDinamica;
//===========================================================================================================================
void  iniciaPilhaDinamica(PilhaDinamica *p){
  p->qtde = 0;
  p->topo = NULL;
}
//===========================================================================================================================
bool estaVaziaPilhaDinamica(PilhaDinamica *p) {
  return(p->topo == NULL);
}
//===========================================================================================================================
void imprimirPilhaDinamica(PilhaDinamica *p) {
  printf("Pilha = [");
  PtrNoPilha aux;
  for(aux = p->topo; aux != NULL; aux = aux->proximo){
    printf("%c ", aux->elemento);
  }
  printf("]\n");
}
//===========================================================================================================================
void pushPilhaDinamica(PilhaDinamica *p, char elemento) {
  PtrNoPilha Aux = malloc(sizeof(NoPilha));
  Aux->elemento = elemento;
  Aux->proximo = p->topo;
  p->topo = Aux;
  p->qtde++;
}
//===========================================================================================================================
void popPilhaDinamica(PilhaDinamica *p) {
  if(!estaVaziaPilhaDinamica(p)) {
    PtrNoPilha aux;
    aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
    p->qtde--;
  } else {
    printf("Warning: pilha está vazia!\n");
  }
}
//===========================================================================================================================
bool entrada_valida (char c){                        //Funcao para identificar se a entrada é valida ou nao.
    if(c>=65&&c<=90||c=='+'||c=='-'||c=='*'||c=='/'){
      return(true);
    }else{
      return(false);
    }
}
//===========================================================================================================================
bool letra (char c){                                 //Funcao para identificar se é um operando ou um operador
  if(c>=65&&c<=90){
    return(true);
  }else{
    return(false);
  }
}
//===========================================================================================================================
void calculo(PilhaDinamica *p, char elemento, FILE* saida){       //funcao para processar os calculos com a formatacao correta
      char intermediaria[2];         
    if(p->qtde>=2){                                   
      for(int a=0;a<2;a++){
        if(p->topo->elemento>=48&&p->topo->elemento<=57){
          fprintf(saida,"LDR TEMP%c\n", p->topo->elemento);
          intermediaria[a]=p->topo->elemento;
          popPilhaDinamica(p);
        }else{
          fprintf(saida,"LDR %c\n", p->topo->elemento);
          intermediaria[a]=p->topo->elemento;
          popPilhaDinamica(p);
        }
      }

      if (intermediaria[0]>=48&&intermediaria[0]<=57){
      if(elemento=='*'){
        fprintf(saida,"MUL TEMP%c", intermediaria[0]);
      }else if(elemento=='+'){
        fprintf(saida,"ADD TEMP%c", intermediaria[0]);
      }else if(elemento=='-'){
        fprintf(saida,"SUB TEMP%c", intermediaria[0]);
      }else if(elemento=='/'){
        fprintf(saida,"DIV TEMP%c", intermediaria[0]);
      }
      }else{
      if(elemento=='*'){
        fprintf(saida,"MUL %c", intermediaria[0]);
      }else if(elemento=='+'){
        fprintf(saida,"ADD %c", intermediaria[0]);
      }else if(elemento=='-'){
        fprintf(saida,"SUB %c", intermediaria[0]);
      }else if(elemento=='/'){
        fprintf(saida,"DIV %c", intermediaria[0]);
      }
      }

      if (intermediaria[1]>=48&&intermediaria[1]<=57){
      if(elemento=='*'){
        fprintf(saida," TEMP%c\n", intermediaria[1]);
      }else if(elemento=='+'){
        fprintf(saida," TEMP%c\n", intermediaria[1]);
      }else if(elemento=='-'){
        fprintf(saida," TEMP%c\n", intermediaria[1]);
      }else if(elemento=='/'){
        fprintf(saida," TEMP%c\n", intermediaria[1]);
      }
      }else{
      if(elemento=='*'){
        fprintf(saida," %c\n", intermediaria[1]);
      }else if(elemento=='+'){
        fprintf(saida," %c\n", intermediaria[1]);
      }else if(elemento=='-'){
        fprintf(saida," %c\n", intermediaria[1]);
      }else if(elemento=='/'){
        fprintf(saida," %c\n", intermediaria[1]);
      }
      }
      reservartemp=1;

  }else{
  printf("Expressao invalida!");
  exit(0);
  }
}
//===========================================================================================================================
void alocatemp(PilhaDinamica *p, FILE* saida){
      char temp;
      if (reservartemp == 1){
        fprintf(saida,"STR TEMP%d\n", global);
        temp = global+48;
        pushPilhaDinamica(p, temp);
        global++;
        reservartemp = 0;
      }

}

//===========================================================================================================================

int main(int argc, char* argv[]) {
    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = fopen(argv[2], "w");
    int retorno;
    char teste;
    PilhaDinamica pilha;

    if (entrada==NULL||saida==NULL){
      printf("Falha em abrir um dos arquivos");
      }
    iniciaPilhaDinamica(&pilha);

    while(retorno!=EOF){
     retorno = fscanf(entrada, " %c", &teste);
    if (retorno!=EOF){
    if(entrada_valida(teste)){            
      alocatemp(&pilha, saida);                                 
      if(letra(teste)){                                             
        pushPilhaDinamica(&pilha, teste);
      }else{
      calculo(&pilha, teste, saida);
      }
    }else{
      fprintf(saida,"Expressao invalida!");
      fclose(entrada);
      fclose(saida);
      exit(0);
    }
  }
}
  return 0;
}