#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
const int tamanho=45;
//============================================================
typedef struct NoArvore* PtrNoArvore;
typedef struct NoArvore {
  char chave[45];
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;
//============================================================
typedef struct palavras {
  char palavra[45];
  int page[15];            
}pesquisa;
//============================================================
void iniciaArvoreBinaria(PtrNoArvore *r) {
  (*r) = NULL;

}
//============================================================
bool estaVaziaArvoreBinaria(PtrNoArvore *r) {
  return((*r) == NULL);
}
//============================================================
bool inserirArvoreBinaria(PtrNoArvore *no, char valor[tamanho]) {
  if((*no) == NULL) {
    (*no) = malloc(sizeof(NoArvore));
    strcpy((*no)->chave, valor);
    (*no)->direita = NULL;
    (*no)->esquerda = NULL;
    return (true);
  }
  int a=0;

  a=strcmp(valor, (*no)->chave);

  if(a>0) {
    return(inserirArvoreBinaria(&(*no)->direita, valor));
  } else if(a<0){
    return(inserirArvoreBinaria(&(*no)->esquerda, valor));
  } else{
    return(false);
  }
}
//============================================================
void PreOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  printf("%s ", (*no)->chave);
  PreOrdemArvoreBinaria(&(*no)->esquerda);
  PreOrdemArvoreBinaria(&(*no)->direita);
}
//============================================================
void PreOrdemPrincipal(PtrNoArvore *no) {
  printf("PreOrdem = { ");
  PreOrdemArvoreBinaria(&(*no));
  printf("}\n");
}
//============================================================
void EmOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return; //clausula base
  EmOrdemArvoreBinaria(&(*no)->esquerda);
  printf("%s ", (*no)->chave);
  EmOrdemArvoreBinaria(&(*no)->direita);
}
//============================================================
void EmOrdemPrincipal(PtrNoArvore *no) {
  printf("EmOrdem = { ");
  EmOrdemArvoreBinaria(&(*no));
  printf("}\n");
}
//============================================================
bool pesquisaArvoreBinaria(PtrNoArvore *no, char valor[tamanho]) {
  if((*no) == NULL) return false;
  int a=0;
  a=strcmp(valor, (*no)->chave);
  if(a>0) {
    return(pesquisaArvoreBinaria(&(*no)->direita, valor));
  } else if(a<0) {
    return(pesquisaArvoreBinaria(&(*no)->esquerda, valor));
  }else if(a==0){
    return true;
  }
}
//============================================================
PtrNoArvore pegarMaiorElemento(PtrNoArvore *no) {
  while ((*no)->direita != NULL) {
    (*no) = (*no)->direita;
  }  
  PtrNoArvore ret = (*no);
  (*no) = (*no)->esquerda; 
  return(ret);
}
//============================================================
bool removerArvoreBinaria(PtrNoArvore *no, char valor[tamanho]) {
  if((*no) == NULL) return false;
  int a=0;
  int b=strlen(valor);
  if((*no)->chave[a] == valor[a]){
    for(a=0;b;a++){
      if((*no)->chave[a] == valor[a]){
        if(a==b-1){
            PtrNoArvore rm = (*no);
            if((*no)->esquerda == NULL && (*no)->direita != NULL) {
            (*no) = (*no)->direita;
            }
            else if((*no)->direita == NULL && (*no)->esquerda == NULL) {
            (*no) = NULL;
            }
            else if((*no)->esquerda != NULL && (*no)->direita == NULL) {
            (*no) = (*no)->esquerda;
            }
            else { 
              rm = pegarMaiorElemento(&(*no)->esquerda);
              strcpy((*no)->chave, rm->chave);
              }
              free(rm);
            return true; 
        }
      }else{
        break;
      }
    }
  } 

  if(valor[a] > (*no)->chave[a]) {
    return(removerArvoreBinaria(&(*no)->direita, valor));
  } else { 
    return(removerArvoreBinaria(&(*no)->esquerda, valor));
  }
}
//============================================================
void ordenartermos(pesquisa ordem[],int contagem){           //Organizar os termos procurados em ordem alfabética;
  int x,y,r;
  char troca[45];
  for(x=0;x<contagem;x++){
    for(y=x+1;y<contagem;y++){
      r = strcmp((ordem)[x].palavra,(ordem)[y].palavra);
      if(r>0){
        strcpy(troca,(ordem)[x].palavra);
        strcpy((ordem)[x].palavra,(ordem)[y].palavra);
        strcpy((ordem)[y].palavra,troca);
      }
    }
  }
}
//============================================================
int main(int argc, const char * argv[]) {
  PtrNoArvore raiz;
  PtrNoArvore ordenar;
  pesquisa termos[9];

  int a=0;
  char teste[45];
  char termo[7]={'t','e','r','m','o','s'};
  char teste1;
  int paginaatual;
  int tamanhovetor, tamanhopalavra, tamanhopalavra1;
  int y, f, k=0, g=0, l=0;
  int retorno;
  int contagepalavra=0;
  char palavra[45];
  char linhadotexto[1200];

  FILE* entrada = fopen(argv[1], "r");
  FILE* saida = fopen(argv[2], "w");

  if (entrada==NULL||saida==NULL){
      fprintf(saida,"Falha em abrir um dos arquivos");
 }

  iniciaArvoreBinaria(&raiz);

  for(int i=0;i<9;i++){
    for(int q=0;q<15;q++){ //Marcar os vetores de pagina com 0;
      termos[i].page[q]=0;
    }
  }

  fscanf(entrada, " %c", &teste1);
    if(teste1 == '<'){
      fscanf(entrada, " %[^:]s", teste);
        if((!strcmp(teste,termo))){
          while(true){
            fscanf(entrada," %c", &teste1);
            if(teste1 == '>'){
              break;
            }
            fscanf(entrada, " %[^,>]s", termos[a].palavra);
            k=0;
            while (termos[a].palavra[k]!='\0'){
              if(termos[a].palavra[k]>=65&&termos[a].palavra[k]<=90){    //Identificar letras maiusculas nos termos e transformar-las e minusculas;
              termos[a].palavra[k]=termos[a].palavra[k]+32;
              }
              k++;
            }
            contagepalavra++;
            a++;
          }
          ordenartermos(termos, contagepalavra);
          fscanf(entrada," %[^\n]s", linhadotexto);
          if(linhadotexto[0]=='<'){
            l=0;
            while (true){
              if(linhadotexto[l]>=48&&linhadotexto[l]<=57){
                paginaatual=linhadotexto[l]-48;                        //Guardar a pagina atual em que a pesquisa está sendo realizada;
                break;
              }
              l++;
            }
          }
            while (true){
              retorno=fscanf(entrada," %[^\n]s", linhadotexto);         //Ler as linhas do textos;
              if(retorno==EOF){

                for(int p=0;p<9;p++){
                  tamanhopalavra1=strlen(termos[p].palavra);
                  if(tamanhopalavra1!=0){
                    if(pesquisaArvoreBinaria(&raiz, termos[p].palavra)){ //Tratamento da ultima pagina;
                      f=0;
                      removerArvoreBinaria(&raiz, termos[p].palavra);
                      while(true){
                        if(termos[p].page[f]==0){
                          termos[p].page[f]=paginaatual;
                          break;
                        }
                        f++;
                      }
                    }
                  } 
                }
                break;
              }
              if(linhadotexto[0]!='<'){
                tamanhovetor=strlen(linhadotexto);
                for(y=0;y<=tamanhovetor;y++){
                  if((linhadotexto[y]>=65&&linhadotexto[y]<=90||linhadotexto[y]>=97&&linhadotexto[y]<=122)&&linhadotexto[y]!='\0'){      //Percorre a string até achar algo que n seja uma letra,                                                                                                                  
                    if(linhadotexto[y]>=65&&linhadotexto[y]<=90){                                                                        //além de identificar letras maiusculas e transformar em minusculas;
                        linhadotexto[y]=linhadotexto[y]+32;
                    }
                    palavra[g]=linhadotexto[y];
                    g++;                    
                  }else{
                    tamanhopalavra=strlen(palavra);
                    if(tamanhopalavra!=0){
                      inserirArvoreBinaria(&raiz, palavra);     //Inseri a palavra na arvore;
                      memset(palavra, 0, 45);
                      g=0;
                    }
                  }
                }                
              }else{
                for(int p=0;p<9;p++){
                  tamanhopalavra1=strlen(termos[p].palavra);
                  if(tamanhopalavra1!=0){
                    if(pesquisaArvoreBinaria(&raiz, termos[p].palavra)){    //Pesquisa o termo, se achar, ele é apagado da arvore e tem a pagina salvada;
                      f=0;
                      removerArvoreBinaria(&raiz, termos[p].palavra);
                      while(true){
                        if(termos[p].page[f]==0){
                          termos[p].page[f]=paginaatual;
                          removerArvoreBinaria(&raiz, termos[p].palavra);
                          break;
                        }
                        f++;
                      }
                    }
                  } 
                }
                tamanhovetor=strlen(linhadotexto);
                for(int g=0;g<tamanhovetor;g++){
                  if(linhadotexto[g]>=48&&linhadotexto[g]<=57){
                    paginaatual=linhadotexto[g]-48;
                  }
                }
              }
            }
            for(int t=0;t<contagepalavra;t++){
              fprintf(saida,"%s", termos[t].palavra);
              for(f=0;f<15;f++){
                if(termos[t].page[f]!=0){
                  fprintf(saida,",%d", termos[t].page[f]);      //Impreção dos resultados;
                }else{
                  fprintf(saida,"\n");
                  break;
                } 
              }
            }
          }
      
    }
  return 0;
}