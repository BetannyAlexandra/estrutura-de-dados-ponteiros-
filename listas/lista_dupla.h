#include <stdio.h>
#include <stdlib.h>


typedef struct cel
{
    int conteudo;
    struct cel *prox;
    struct cel *ant;
} celula;

void inseririnicio(celula **ptrhead, int valor)
{
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = *ptrhead;
    nova->ant = NULL;
    if (*ptrhead != NULL)
    {
        (*ptrhead)->ant = nova;
    }

    *ptrhead = nova;
}
void inserirfim(celula **head, int valor)
{
    celula *aux = *head;
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = NULL;
    if (*head == NULL)
    {
        *head = nova;
        nova->ant = NULL;
    }
    else
    {
        while (aux->prox != NULL)
        {

            aux = aux->prox;
        }

        aux->prox = nova;
        nova->ant = aux;
    }
}

void inserirmeio(celula **head, int valor, int ref)
{
    celula *aux = *head;
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = valor;
    if (*head == NULL)
    {
        nova->prox = NULL;
        nova->ant = NULL;
        *head = nova;
    }
    else
    {
        while (aux->conteudo != ref && aux->prox != NULL)
        {
            aux = aux->prox;
        }
        nova->prox = aux->prox;
        if (aux->prox != NULL)
        {
            aux->prox->ant = nova;
        }
        nova->ant = aux;
        aux->prox = nova;
    }
}

void concatenar(celula *head, celula *head2)
{
    celula *aux = head;
    while (aux->prox != NULL)
    {

        aux = aux->prox;
    }

    aux->prox = head2;
    head2->ant = aux;
}
void imprimir(celula *aux)
{
    while (aux != NULL)
    {
        printf("%d->", aux->conteudo);
        aux = aux->prox;
    }
}