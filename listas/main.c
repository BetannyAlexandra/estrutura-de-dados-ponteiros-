#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"



int main()
{
    celula *c = NULL;
    int cel = 7, valor, ref;

    while (cel != 0)
    {
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
            inserirmeio(&c, valor, ref);
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



    return 0;
}