#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int conteudo;
    struct cel *prox;
    struct cel *ant;

} celula;

void inseririnicio(celula **ptrhead, int *valor)
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

int main()
{
    celula *c = NULL;
    int cel=7, valor,ref;

    while (cel != 0){ 
    printf("Preencha a lista\n");
    printf("1-Inserir no inicio\n");
    printf("2-Inserir no fim\n");
    printf("3-Inserir no meio\n");
    printf("4-concatenar\n");
    printf("4-Imprimir\n");
    printf("0-sair\n");
    scanf("%d", &cel);


        switch (cel)
        {
        case 1:
            printf("informe o valor que deseja inserir\n");
            scanf("%d", &valor);
            inseririnicio(&c, valor);
            break;

        case 2:
            printf("após que valor deseja inserir?\n");
            scanf("%d", &ref);
            printf("informe o valor que deseja inserir\n");
            scanf("%d", &valor);
            inserirmeio(&c, valor,ref);
            break;
        case 3:
            printf("informe o valor que deseja inserir\n");
            scanf("%d", &valor);
            inserirfim(&c, valor);

        case 4:
        imprimir(c);
        break;
        case 0:

        break;
        default:
            break;
        }
    }

    /*inseririnicio(&c, 6);
    inseririnicio(&c, 7);
    /*inserirfim(&c,10);
    inserirfim(&c,11);
    inserirmeio(&c, 10, 6);

    imprimir(c);*/

    return 0;
    
}