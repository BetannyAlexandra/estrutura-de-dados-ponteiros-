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

elemnet *inversa(elemnet **top)
{

    elemnet *top2 = NULL;

    if (*top == NULL)
    {
        top2 = NULL;
    }
    else
    {
        while (*top != NULL)
        {
            push(&top2, pop(top));
        }
    }

    return top2;
}

void imprimir(elemnet *aux)
{
    while (aux != NULL)
    {
        printf("elem=%d\n", aux->conteudo);
        aux = aux->prox;
    }
}

int main()
{

    elemnet *top = NULL;
    elemnet e1, e2, e3, e4;
    e1.conteudo = 20;
    e2.conteudo = 30;
    e3.conteudo = 40;
    e4.conteudo = 50;
    printf("Pilha\n");
    push(&top, &e1);
    push(&top, &e2);
    push(&top, &e3);
    push(&top, &e4);
    imprimir(top);
    elemnet *top2 = inversa(&top);
    printf("Pilha inversa\n");
    imprimir(top2);

    return 0;
}