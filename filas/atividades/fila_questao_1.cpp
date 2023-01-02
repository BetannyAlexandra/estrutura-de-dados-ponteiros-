#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
    char nome[50];
    char plano_saude[100];
    int idade;
    struct elem *prox;
} element;

void enqueue(element **last, element *e, element **first = NULL){
    e->prox = NULL;
    if (*last == NULL)
    {
        *first = e;
        *last = e;
        return;
    }
    (*last)->prox = e;
    *last = e;
}

element *dequeue(element **first, element **last = NULL){
    if (*first == NULL)
    {
        return NULL;
    }
    element *front = *first;
    (*first) = (*first)->prox;
    if (*first == NULL)
    {
        *last == NULL;
    }
    front->prox = NULL;
    return front;
}

void print(element *aux){
    while (aux != NULL){
        printf("%s\n", aux->nome);
        printf("%s\n", aux->plano_saude);
        printf("%d\n", aux->idade);
        aux = aux->prox;
    }
    printf("NULL\n");
}
int pessoas_na_frente(element *first, char *nome){

    int s = 0;
    while (first != NULL){
        
        if (strcmp(first->nome, nome) == 0){
            return s;
        }
        first = first->prox;
        s++;
    }
    return -1;
}

int main(){
    element *first = NULL, *last = NULL;
    int tam;
    printf("qual o tamanho da fila?");
    scanf("%d", &tam);
    for (int i = 1; i <= tam; i++){
        element *e = (element *)malloc(sizeof(element));
        printf("Insira o nome do paciente: ");
        scanf("%s", e->nome);
        printf("Insira o plano de saude do paciente: ");
        scanf("%s", e->plano_saude);
        printf("Insira a idade do paciente: ");
        scanf("%d", &e->idade);
        if (first == NULL){
            enqueue(&last, e, &first);
        }
        else enqueue(&last, e);
    }
    print(first);
    char nome[30];
    printf("pessoa a ser procurada: ");
    scanf("%s", nome);
    printf("pessoas na frente: %d", pessoas_na_frente(first,nome));
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
typedef struct paciente
{
    char nome[100];
    int cpf;
    struct paciente *prox;

} paciente;


    paciente *prim_emergencia = NULL;
    paciente *prim_urgencia = NULL;
    paciente *prim_eletivo = NULL;
    paciente *ult_emergencia = NULL;
    paciente *ult_urgencia = NULL;
    paciente *ult_eletivo = NULL;


paciente *dados_paciente (){
    paciente *nova = (paciente *)malloc(sizeof(paciente));
    
            printf("inserir paciente na fila de urgencia:\n");
            printf("Nome do paciente:\n");
            scanf("%s", nova->nome);
            printf("CPF do paciente:\n");
            scanf("%d", &nova->cpf);
return nova;
}
void enfileirar(paciente **last, paciente *nova, paciente **first = NULL)
{
    nova->prox = NULL;
    if (*last == NULL)
    {
        *first = nova;
        *last = nova;
    }
    else
    {
        (*last)->prox = nova;
        *last = nova;
    }
}
/*int pessoas_na_frente(paciente*first, int *cpf){

    int tam = 0;
    while (first != NULL){
        
        if (first->cpf==cpf){
            return tam;
        }
        first = first->prox;
        tam++;
    } 
    return -1;
}*/
void imprimir_menu()

{
    printf("\n\n");
    printf("*******\t\tMENU\t********\n");
    printf("*\t1 - Inserir paciente na fila de urgencia\t*\n");
    printf("*\t2- Inserir paciente na fila de emergencia\t*\n");
    printf("*\t3 - Inserir paciente na fila de eletivos\t*\n");
    printf("*\t0 - Sair\t\t*\n");
}


int main()
{
    int opc =-1;
    while (opc != 0)
    {
        imprimir_menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
        
            enfileirar(&ult_urgencia,dados_paciente(),&prim_urgencia);
            break;
        /*case 2:
            printf("inserir paciente na fila de emergencia:\n");
            printf("Nome do paciente:\n");
            scanf("%s", nova->nome);
            printf("CPF do paciente:\n");
            scanf("%d", &nova->cpf);
            enfileirar(&ult_emergencia, nova);
            break;

        case 3:
            printf("inserir paciente na fila de eletivos:\n");
            printf("Nome do paciente:\n");
            scanf("%s", nova->nome);
            printf("CPF do paciente:\n");
            scanf("%d", &nova->cpf);
            enfileirar(&ult_eletivo, nova);
            break;*/

        default:
          printf("opção invalida");
            break;
        }
    }
    return 0;
}
