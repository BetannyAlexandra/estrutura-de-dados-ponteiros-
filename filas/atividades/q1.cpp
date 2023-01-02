#include <stdio.h>
#include <stdlib.h>


typedef struct paciente {
  char nome[50];
  char plano_saude[100];
  int idade;
  struct paciente *prox;
  
} paciente;


void enfileirar(paciente **last,paciente *nova,paciente **first=NULL){
nova->prox=NULL;
if(*last==NULL){
    *first=nova;
    *last=nova;
}else{
   paciente *novo= (paciente*)malloc(sizeof(site));
    printf("nome do paciente: ");
    scanf("%s", novo->nome);
    printf("idade do paciente ");
    scanf("%d", novo->idade);
    printf("plano de saude ");
    scanf("%s", novo->plano_saude);
    (*last)->prox=nova;
    *last=nova;
}
}

int pessoas_naFila(paciente*aux, char *nome){
    int tam=0;
    while(aux!=NULL){
        tam++;
        if( ==aux->conteudo){
            return tam;
        } 
        aux=aux->prox;
    }
    return -1;
}
