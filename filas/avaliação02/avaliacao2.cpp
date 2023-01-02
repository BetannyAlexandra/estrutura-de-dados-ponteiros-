#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente
{
    char nome[100];
    char nivel[20];
    char cpf[12];
    struct paciente *prox;

} paciente;

paciente *prim_emergencia = NULL;
paciente *prim_urgencia = NULL;
paciente *prim_eletivo = NULL;
paciente *ult_emergencia = NULL;
paciente *ult_urgencia = NULL;
paciente *ult_eletivo = NULL;

int emergencia = 0;
int urgencia = 0;
int eletivos = 0;
int chamada = 0;

paciente *dados_paciente(char *nivel)
{
    paciente *nova = (paciente *)malloc(sizeof(paciente));
    printf("inserir paciente :\n");
    printf("Nome do paciente:\n");
    scanf("%s", nova->nome);
    printf("CPF do paciente:\n");
    scanf("%s", nova->cpf);
    strcpy(nova->nivel, nivel);

    return nova;
}


paciente *dequeue(paciente **first, paciente **last)
{
    if (*first == NULL)
    {
        return NULL;
    }
    paciente *front = *first;
    (*first) = (*first)->prox;
    if (*first == NULL)
    {
        *last = NULL;
    }
    front->prox = NULL;
    printf("funcionou\n");
    return front;
}

void encontrar(){
    while(prim_eletivo!=NULL){
       if( prim_eletivo->prox==NULL){
        return prim_eletivo;
       }
    }
}

paciente *next()
{
    paciente *proximo = NULL;

    if (prim_emergencia != NULL)
    {
        proximo = dequeue(&prim_emergencia, &ult_emergencia);

        emergencia++;
        return proximo;
    }

    if (prim_urgencia != NULL && (chamada % 3 != 0 || chamada == 0))
    {
        proximo = dequeue(&prim_urgencia, &ult_urgencia);
        urgencia++;
        chamada++;
        return proximo;
    }
    if (prim_eletivo != NULL)
    {
        proximo = dequeue(&prim_eletivo, &ult_eletivo);
        eletivos++;
        chamada++;
        return proximo;
    }
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

void total()
{

    printf("Total de pacientes atendidos na fila de emergencia:%d\n", emergencia);

    printf("Total de pacientes atendidos na fila de urgencia:%d\n", urgencia);

    printf("Total de pacientes atendidos na fila de eletivos:%d\n", eletivos);

    int total = emergencia + urgencia + eletivos;
    printf("Total de pacientes atendidos :%d\n", total);
}

int frente_cpf(char *cpf)
{

    paciente *aux_emergencia = prim_emergencia;
    paciente *aux_urgencia = prim_urgencia;
    paciente *aux_eletivo = prim_eletivo;

    int contador = -1;
    int urg = 0;
    int elet = 0;

    while (aux_emergencia != NULL)
    {
        contador++;

         if ( strcmp (aux_emergencia-> cpf , cpf) == 0 )
        {
            return contador;
        }
        aux_emergencia = aux_emergencia->prox;
    }

    while (aux_urgencia != NULL || aux_eletivo != NULL)
    {
        while (urg != 3 && aux_urgencia != NULL)
        {
            contador++;
            urg++;
            elet = 0;
        

         if ( strcmp (aux_urgencia-> cpf , cpf) == 0 )
        {
            return contador;
        }
        aux_urgencia = aux_urgencia->prox;

        if (aux_eletivo == NULL)
        {
            urg = 0;
        }
        }
    }
    while (elet != 1 && aux_eletivo != NULL)
    {
        contador++;
        elet++;
        urg = 0;
         if ( strcmp (aux_eletivo-> cpf , cpf) == 0 )
        {
            return contador;
        }
        aux_eletivo = aux_eletivo->prox;
    
    if (aux_urgencia == NULL)
    {
        elet = 0;
    }
    }

    return -1;
}
void print(paciente *aux)
{
    while (aux != NULL)
    {
        printf("Nome do paciente:%s\n -> ", aux->nome);
        printf("CPF do paciente:%s\n -> ", aux->cpf);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void imprimir_menu()

{
    printf("\n\n");
    printf("*******\t\tMENU\t********\n");
    printf("*\t1 - Inserir paciente na fila de emergencia\t*\n");
    printf("*\t2- Inserir paciente na fila de uegencia\t*\n");
    printf("*\t3 - Inserir paciente na fila de eletivos\t*\n");
    printf("*\t4 - Atender paciente\t*\n");
    printf("*\t5 - imprimir total de pacientes atendidos\t*\n");
    printf("*\t6 - imprimir filas de pacientes\t*\n");
    printf("*\t7 - Saber quantos pacientes tem antes do paciente desejado de acordo com o cpf\t*\n");
    printf("*\t0 - Sair\t\t*\n");
}

int main()
{
    char cpf[12];
    int posicao;
    int opc = 1;

    while (opc != 0)
    {
        imprimir_menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            enfileirar(&ult_emergencia, dados_paciente("emergencia"), &prim_emergencia);

            break;
        case 2:
            enfileirar(&ult_urgencia, dados_paciente("urgencia"), &prim_urgencia);
            break;

        case 3:
            enfileirar(&ult_eletivo, dados_paciente("eletivos"), &prim_eletivo);
            break;
        case 4:
            print(next());

            break;
        case 5:
            total();
            break;
        case 6:
            printf("Pacientes de emergencia:\n");
            print(prim_emergencia);
            printf("Pacientes de urgencia:\n");
            print(prim_urgencia);
            printf("Pacientes de eletivos:\n");
            print(prim_eletivo); 
            break;

        case 7:
        printf("informe o  cpf do paciente:");
        scanf("%s",cpf);


        posicao=frente_cpf(cpf);
        printf("Tem %d paciente(s) antes do paciente de cpf %s\n",posicao,cpf);
        
        break;


        case 0:
            printf("Encerrado");
            break;
        default:
            printf("opção invalida");
            break;
        }
    }
    return 0;
}
