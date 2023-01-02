#include <stdio.h>
#include <stdlib.h>
typedef struct elem
{
    int conteudo;
    struct elem *prox;

} elemnet;
void push(elemnet **top, elemnet *nova)
{
    nova->prox = *top;
    *top = nova;
}

elemnet *pop(elemnet **top)
{
    if (*top == NULL)
    {
        return NULL;
    }
    else
    {
        elemnet *p = *top;
        *top = (*top)->prox;
        p->prox = NULL;
        return p;
    }
}

void clear(elemnet **top)
{
    elemnet *aux = pop(top);
    while (aux != NULL)
    {
        aux = pop(top);
    }
}

void imprimir(elemnet *aux)
{
    while (aux != NULL)
    {
        printf("%d\n", aux->conteudo);
        aux = aux->prox;
    }
}

int size(elemnet *aux)
{
    int s = 0;
    while (aux != NULL)
    {
        s++;
        aux = aux->prox;
    }
    return s;
}
int position(elemnet *aux, elemnet *e)
{
    int s = 0;
    while (aux != NULL)
    {
        s++;
        if (e->conteudo == aux->conteudo)
        {
            return s;
        }
        aux = aux->prox;
    }
    return -1;
}

int main()
{

    elemnet *top = NULL;
    elemnet e1, e2, e3,e4;
    e1.conteudo = 20;
    e2.conteudo = 30;
    e3.conteudo = 40;
    e4.conteudo=50;


    push(&top, &e1);
    push(&top, &e2);
    push(&top, &e3);
        push(&top, &e4);
    imprimir(top);

           


               
  printf("Tam: %d\n", size(top));

    return 0;
}