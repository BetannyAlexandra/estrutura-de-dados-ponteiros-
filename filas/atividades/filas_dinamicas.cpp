#include <stdio.h>
#include <stdlib.h>
typedef struct elem
{
    int conteudo;
    struct elem *prox;

} elemnet;

void enfileirar(elemnet **last,elemnet *nova,elemnet **first=NULL){
nova->prox=NULL;
if(*last==NULL){
    *first=nova;
    *last=nova;
}else{
    (*last)->prox=nova;
    *last=nova;
}
}

elemnet *desinfileirar(elemnet **first,elemnet **last=NULL){
    if(*first==NULL){
        return NULL;
    }
    
        elemnet *front=*first;
        (*first)=(*first)->prox;
 if (*first == NULL) {
    *last == NULL;
  }
  front->prox=NULL; 
  return front;

}


void print(elemnet *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void limpar(elemnet **first){
    elemnet *aux=desinfileirar(first);
    while(aux!=NULL){
        aux=desinfileirar(first);

    }
}

int posicao(elemnet *aux, elemnet *el){
    int tam=0;
    while(aux!=NULL){
        tam++;
        if(el->conteudo==aux->conteudo){
            return tam;
        } 
        aux=aux->prox;
    }
    return -1;
}
