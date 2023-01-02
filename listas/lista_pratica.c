#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    char nome[30];
    float n1;
    float n2;
    float n3;
    float media;
    struct lista *prox;
} Aluno;

void aluno_maior_media(Aluno *p)
{
    Aluno *aux = p;
    int maior = 0;
    while (p != NULL)
    {
        if (p->media > maior)
        {
            maior = p->media;
            aux = p;
        }
        p = p->prox;
    }
    printf("%s(%.1f,%.1f,%.1f) --> ", aux->nome, aux->n1, aux->n2, aux->n3);
}

void alunos_recuperacao(Aluno *p)
{

    Aluno *ptraux=NULL;
    Aluno *apr;
    int rec = 7;
    while (p != NULL)
    {

        if (p->media < rec)
        {

            printf("\naluno de recuperação=%s --> ", p->nome);
        }
        else
        {
            
            ptraux->prox=p->prox;
            apr=p;
            
            free(apr);
        }
        ptraux=p;
        p = p->prox;
    }
}

Aluno *adiciona_aluno(Aluno *p)
{

    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));

    printf("Digite o nome do aluno: ");
    scanf("%s", &novo->nome);

    printf("Digite a 1Âª nota do aluno: ");
    scanf("%f", &novo->n1);

    printf("Digite a 2Âª nota do aluno: ");
    scanf("%f", &novo->n2);

    printf("Digite a 3Âª nota do aluno: ");
    scanf("%f", &novo->n3);
    novo->media = ((novo->n1 + novo->n2 + novo->n3) / 3);
    novo->prox = p;
    printf("media=%f", novo->media);

    return novo;
}

void imprimir(Aluno *p)
{
    printf("Lista de alunos:\n");
    while (p != NULL)
    {
        printf("%s(%.1f,%.1f,%.1f) --> ", p->nome, p->n1, p->n2, p->n3);
        p = p->prox;
    }
    printf("NULL\n");
}

void desaloca_lista(Aluno *p)
{
    Aluno *prox = p;
    while (p != NULL)
    {
        prox = p->prox;
        free(p);
        p = prox;
    }
}

int main()
{

    Aluno *cabeca = NULL;

    int opt = 0;
    do
    {
        if (opt != 0)
        {
            printf("\nAperte Enter para continuar\n");
            getchar();
            getchar();
        }
        printf("\n|\t**********************************\t|\n");
        printf("|\t\t\tMENU\t\t\t|\n");
        printf("|\t1-Adicionar aluno\t\t\t|\n");
        printf("|\t2-Imprimir lista\t\t\t|\n");
        printf("|\t3-Imprimir aluno com maior mÃ©dia\t|\n");
        printf("|\t4-Imprimir alunos de recuperaÃ§Ã£o\t|\n");
        printf("|\t0-Sair\t\t\t\t\t|\n");
        printf("|\t**********************************\t|\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opt);
        printf("\n");
        switch (opt)
        {
        case 1:
            cabeca = adiciona_aluno(cabeca);
            break;
        case 2:
            imprimir(cabeca);
            break;
        case 3:
            aluno_maior_media(cabeca);
            break;
        case 4:
            alunos_recuperacao(cabeca);
            break;
        case 0:
            break;
        default:
            printf("OpÃ§Ã£o invÃ¡lida\n");
            break;
        }

    } while (opt != 0);

    desaloca_lista(cabeca);

    return 0;
}