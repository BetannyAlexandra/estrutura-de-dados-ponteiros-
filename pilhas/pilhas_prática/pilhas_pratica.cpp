#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg
{
    char nome[100];
    char link[100];
    struct reg *prox;
} site;





void push(site **top)
{
    site *sit = (site *)malloc(sizeof(site));
    printf("nome do site: ");
    scanf("%s", sit->nome);
    printf("link do site: ");
    fflush(stdin);
    scanf("%s", sit->link);
    sit->prox = *top;
    *top = sit;
}


site *pop(site **top)
{
    if (*top == NULL)
    {
        return NULL;
    }
    else
    {
        site *p = *top;
        *top = (*top)->prox;
        p->prox = NULL;
        return p;
    }
}
site *voltar(site *top,int n){
    for (int i = 0; i <=n; i++)
    {
        pop(&top);
    }
    return top;
}
void imprimir(site *aux)
{
    while (aux != NULL)
    {
        printf("nome do site:%s\n", aux->nome);
        printf("link do site:%s\n", aux->link);
        aux = aux->prox;
    }
}

void imprimir_menu()
{
    printf("\n\n");
    printf("*******\t\tMENU\t********\n");
    printf("\t1 - Adicionar Site\t\n");
    printf("\t2 - Voltar Site\t\n");
    printf("\t3 - Imprimir Sites\t\n");
    printf("\t0 - Sair\t\t*\n");
}
int main()
{

    site *top = NULL;
    int op = -1;
    int quantidade;
    while (op != 0)
    {
        imprimir_menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            push(&top);
            break;

        case 2:

        printf("Informe a quantidade de links que deseja voltar\n");
        scanf("%d",&quantidade);

        top=voltar(top,quantidade);
        printf("link que escolheu:%d\n",top);

         
            break;

        case 3:

            imprimir(top);
            break;
        default:
            break;
        }
    }
    imprimir(top);
    return 0;
}