#include <stdio.h>
#include <stdlib.h>
#include "circular.h"


int  main () {
  celula *head= NULL;
    int cel = 0, valor;

    while (cel != 5)
    {
        printf("Preencha a lista\n");
        printf("1-Inserir no inicio\n");
        printf("2-Inserir no fim\n");
        printf("3-Inserir no meio\n");
        printf("4-Imprimir\n");
        printf("5-sair\n");
        scanf("%d", &cel);

        switch (cel)
        {
        case 1:
            printf("informe o valor que deseja inserir\n");
            scanf("%d", &valor);
            inserir(&head, valor);
            break;

    
        case 3:
           
            remover(&head);

        case 4:
            imprimir(head);
            break;
        case 5:


            break;
        default:
            break;
        }
    }

  

    return 0;

}