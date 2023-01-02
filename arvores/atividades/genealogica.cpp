#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
   char nome[20];
    int idade;
}pessoa;

typedef struct  no
{
   pessoa *pessoa;
   struct no *filho1;
 struct no *filho2;
  struct no *filho3;
}node;

node *criar_no(){
    pessoa *p=(pessoa*)malloc(sizeof(pessoa));
    node *no=(node*)malloc(sizeof(node));

  printf("Digite o nome: ");
  scanf(" %s", p->nome);
  printf("Digite a idade: ");
  scanf("%d", &p->idade);

  no->pessoa=p;
  no->filho1=NULL;
  
  no->filho2=NULL;
  
  no->filho3=NULL;

  return no;
}

