#include <stdio.h>
#include <stdlib.h>
typedef struct cel{
    int conteudo;
    struct cel *prox;
    struct cel *ant;
    
}celula;

void inseririnicio(celula **ptrhead,int *valor){
    celula *nova=(celula*)malloc(sizeof(celula));
    nova->conteudo=valor;
    nova->prox=*ptrhead;
    nova->ant=NULL;
    *ptrhead=nova;


}
void inserirfim(celula *head,int valor)
{   celula *aux=head;
    celula *nova=(celula*)malloc(sizeof(celula));
     nova->conteudo=valor;
     nova->prox=NULL;
    while(aux!=NULL){
     if(aux->prox==NULL)
       { 
       nova->ant=aux;
       aux->prox=nova;
       }
      aux=aux->prox; 
      }

    


}
void imprimir(celula *aux)
{
    while(aux!=NULL){
        printf("%d->",aux->conteudo);
        aux=aux->prox;
    }

}
int main(){

 int valor,valor2;
  celula c1;
  celula c2;
  celula c3;
  celula c4;
  celula c5;

  c1.conteudo = 1;
  c2.conteudo = 2;
  c3.conteudo = 3;
  c4.conteudo = 4;
  c5.conteudo = 5;

  c1.ant = NULL;
  c1.prox = &c2;
  c2.ant = &c1;
  c2.prox = &c3;
  c3.ant = &c2;
  c3.prox = &c4;
  c4.ant = &c3;
  c4.prox = &c5;
  c5.ant = &c4;
  c5.prox = NULL;

  

  celula *head=&c1;
  imprimir(head);
  printf("informe o valor que deseja inserir no inicio\n");
  scanf("%d",&valor);
  inseririnicio(&head,valor);
  printf("informe o valor que deseja inserir no fimm\n");
  scanf("%d",&valor2);
  /*inserirfim(&head,valor2)*/;
   printf("valores inseridos\n");
  imprimir(head);
    return 0;

}