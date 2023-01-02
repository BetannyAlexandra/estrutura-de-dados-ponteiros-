#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    char nome[50];
    char link[100];
    struct elem *prox;
} element;
void push(element **top) {
    element *e = (element *)malloc(sizeof(element));
    printf("nome do site: ");
    scanf("%s",e->nome);
    printf("link do site: ");
    fflush(stdin);
    scanf("%s",e->link);
    fflush(stdin);
    e->prox = *top;
    *top = e;
}
element *pop(element **top) {
  if (*top == NULL) {
    return NULL;
  }
  element *p = *top;
  *top = (*top)->prox;
  p->prox = NULL;
  return p;
}

element *voltar(element *top,int n){
    for(int i=0;i<=n;i++){
        pop(&top);
    }
    return top;
}
void print_sites(element *top){
    if(top==NULL){
        printf("NULL");
        return;
    }
    while(top!=NULL){
    printf("nome do site: %s\nlink do site: %s", top->nome,top->link);
    top=top->prox;
    }
}
void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("\t1 - Adicionar Site\t\n");
  printf("\t2 - Voltar Site\t\n");
  printf("\t3 - Imprimir Sites\t\n");
  printf("\t0 - Sair\t\t*\n");
}
int main(){
    element *top=NULL;
    int op=-1;
    int qnt_voltar;
    element *nova;
    while(op!=0){
        imprimir_menu();
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1:
            push(&top);
            break;
            case 2:
            printf("quantos sites voltar: ");
            scanf("%d", &qnt_voltar);
            top = voltar(top,qnt_voltar);
            break;
            case 3:
            print_sites(top);
            break;
        }
    }
    return 0;
}