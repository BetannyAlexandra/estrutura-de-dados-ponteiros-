
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct só pra armazenar a passagem
typedef struct passagem
{
  char data[10];
  float preco;
  int localizador;
  char destino[50];
} passagem;
// struct pra armazenar os dados da arvore
typedef struct node
{
  passagem pessoa;
  struct node *esq;
  struct node *dir;
} no;

// arvore pra armazenar a passagem dos dois paises
no *argentina = NULL;
no *brasil = NULL;
no *consolidada = NULL;
// contadores pra armazenar o numero de passagens de cada pais e o preço total vendido
int cont_argentina = 0;
int cont_brasil = 0;
int contador_preco = 0;

// função pra somar as passagens vendidas
int soma(no *node)
{
  if (node == NULL)
    return -1;
  contador_preco = contador_preco + (node->pessoa.preco);

  soma(node->dir); // recursividade
  soma(node->esq); // recursividade

  return contador_preco;
}

no *criar_passagem()
{
  int loc = rand() % 100;
  no *pass = (no *)malloc(sizeof(no));

  printf("Escolha a data:\n ");
  scanf("%s", pass->pessoa.data);

  printf("Escolha o destino:\n ");
  scanf("%s", pass->pessoa.destino);

  printf("Escolha o preço:");
  scanf("%f", &pass->pessoa.preco);

  pass->pessoa.localizador = loc;
  printf("%d\n", pass->pessoa.localizador);

  pass->esq = NULL;
  pass->dir = NULL;

  return pass;
}
void inserir_passagem(no *node, no *novo)
{
  if (node == NULL)
  {
    printf("Erro\n");
    return;
  }

  if (node->pessoa.localizador == novo->pessoa.localizador)
  {
    printf("Número já existe\n");
    return;
  }

  if (node->pessoa.localizador < novo->pessoa.localizador)
  {
    if (node->dir == NULL)
    {
      node->dir = novo;
      return;
    }
    inserir_passagem(node->dir, novo);
  }
  else
  {
    if (node->esq == NULL)
    {
      node->esq = novo;
      return;
    }
    inserir_passagem(node->esq, novo);
  }
}
void inserir_raiz(no **raiz)
{
  if (*raiz == NULL)
  {
    *raiz = criar_passagem();
    return;
  }

  no *novo = criar_passagem();
  inserir_passagem(*raiz, novo);
}
void menu()
{

  printf("MENU\n");
  printf("1-Passagem para Argentina\n");
  printf("2-Passagem para Brasil\n");
  printf("3-buscar passagem para Argentina\n");
  printf("4-buscar passagem para Brasil\n");
  printf("5-Faturamento da Argentina\n");
  printf("6-Faturamento do Brasil\n");
  printf("7-Total de voos realizados\n");
  printf("8-Vendas consolidadas\n");
  printf("0-Sair\n");
}

void imprimir_no(no *node)
{

  if (node == NULL)
  {
    return;
  }
  printf("%s\n", node->pessoa.data);
  printf("%s\n", node->pessoa.destino);
  printf("%f\n", node->pessoa.preco);
}
no *buscar_pai(no *node, int num)
{
  if (node == NULL)
    return NULL;

  if ((node->esq != NULL) && (node->esq->pessoa.localizador == num))
  {
    return node;
  }

  if ((node->dir != NULL) && (node->dir->pessoa.localizador == num))
  {
    return node;
  }

  if (node->pessoa.localizador < num)
  {
    return buscar_pai(node->dir, num);
  }
  else
  {
    return buscar_pai(node->esq, num);
  }
}

bool um_filho(no *node)
{
  // return (node->esquerda == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir != NULL))
  {
    return true;
  }

  if ((node->esq != NULL) && (node->dir == NULL))
  {
    return true;
  }

  return false;
}

bool eh_folha(no *node)
{
  // return (node->esquerda == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir == NULL))
  {
    return true;
  }
  else
  {
    return false;
  }
}

no *maior(no *node)
{
  if (node == NULL)
    return NULL;
  if (node->dir == NULL)
    return node;
  return maior(node->dir);
}

no *remover(no *node, int num);

void substituir(no *pai, no *removido)
{
  if (um_filho(removido))
  {
    if (removido->esq != NULL)
    {
      pai->esq = removido->esq;
    }
    else
    {
      pai->dir = removido->dir;
    }
  }
  else
  {
    no *substituto = maior(removido->esq);
    remover(pai, substituto->pessoa.localizador);
    substituto->esq = removido->esq;
    substituto->dir = removido->dir;
    if (pai->pessoa.localizador < substituto->pessoa.localizador)
    {
      pai->dir = substituto;
    }
    else
    {
      pai->esq = substituto;
    }
    removido->dir = NULL;
    removido->esq = NULL;
  }
}

no *remover(no *node, int num)
{
  no *pai = buscar_pai(node, num);
  if (pai == NULL)
  {
    printf("Numero não encontrado");
    return NULL;
  }
  else
  {
    // printf("Pai: %d\n", pai->num);
    no *removido = NULL;
    if (pai->pessoa.localizador < num)
    {
      removido = pai->dir;
      if (eh_folha(removido))
      {
        pai->dir = NULL;
      }
      else
      {
        substituir(pai, removido);
      }
    }
    else
    {
      removido = pai->esq;
      if (eh_folha(removido))
      {
        pai->esq = NULL;
      }
      else
      {
        substituir(pai, removido);
      }
    }
    // printf("Removido: %d\n", removido->num);
    return removido;
  }
}

void arvore_consolidada(no **raiz, no *node)
{
  if (*raiz == NULL)
  {
    *raiz = node;
    return;
  }
  if (((*raiz)->pessoa.localizador) < (node->pessoa.localizador))
  {
    if ((*raiz)->dir == NULL)
    {
      (*raiz)->dir = node;
      return;
    }
    arvore_consolidada(&(*raiz)->dir, node);
  }
  else
  {
    if ((*raiz)->esq == NULL)
    {
      (*raiz)->esq = node;
      return;
    }
    arvore_consolidada(&(*raiz)->esq, node);
  }
}

void remover_raiz(no **raiz)
{
  if (*raiz == NULL)
  {
    printf("Árvore vazia\n");
    return;
  }

  int num = (*raiz)->pessoa.localizador;

  if ((*raiz)->pessoa.localizador == num)
  {
    if (eh_folha(*raiz))
    {
      arvore_consolidada(&consolidada, *raiz);
      *raiz = NULL;
      return;
    }

    if (um_filho(*raiz))
    {
      no *remover = *raiz;
      if ((*raiz)->esq != NULL)
      {
        *raiz = (*raiz)->esq;
        remover->esq = NULL;
      }
      else
      {
        *raiz = (*raiz)->dir;
        remover->dir = NULL;
      }
      arvore_consolidada(&consolidada, remover);
    }
    else
    {
      no *substituto = maior((*raiz)->esq);

      remover(*raiz, substituto->pessoa.localizador);

      substituto->esq = (*raiz)->esq;
      substituto->dir = (*raiz)->dir;

      (*raiz)->esq = NULL;
      (*raiz)->dir = NULL;

      arvore_consolidada(&consolidada, *raiz);

      *raiz = substituto;
    }
  }
}

void consolidar(no **root)
{
  while ((*root) != NULL)
  {
    remover_raiz(root);
  }
}

void buscar_destino(no *no, char *destino)
{
  if (no == NULL)
  {
    return;
  }
  if (strcmp(no->pessoa.destino, destino) == 0)
  {
    imprimir_no(no);
  }

  buscar_destino(no->dir, destino);
  buscar_destino(no->esq, destino);
}

int main()
{
  srand(time(NULL));
  int preco_arg;
  int preco_br;
  char destino[30];
  int opc = -1;
  while (opc != 0)
  {
    menu();
    scanf("%d", &opc);
    switch (opc)
    {
    case 1: // vender passagem pra argentina
      inserir_raiz(&argentina);
      cont_argentina++;
      break;
    case 2: // vender passagem para o brasil
      inserir_raiz(&brasil);
      cont_brasil++;
      break;
      // case 3: // imprimir passagem pra argentina
      //   imprimir(argentina);
      //   break;
      //   case 4:
      //   imprimir(brasil);
      //     break;

    case 3: // buscar destino pra argentina
      printf("informe o destino que deseja buscar\n");
      scanf("%s", destino);
      buscar_destino(argentina, destino);
      break;

    case 4: // buscar destino para brasil
      printf("informe o destino que deseja buscar\n");
      scanf("%s", destino);

      buscar_destino(brasil, destino);

      break;

    case 5: // faturamento argentina
      preco_arg = soma(argentina);
      printf("Faturamento - Argentina: %d\n", preco_arg);

      printf("faturamento total = %d", preco_arg + preco_br);
      contador_preco = 0;

      break;
    case 6: // faturamento brasil
      preco_br = soma(brasil);
      printf("Faturamento - Brasil: %d\n", preco_br);
      printf("faturamento total = %d", preco_arg + preco_br);
      contador_preco = 0;
      break;
    case 7: // total de voos realizados
      printf("Quantidade de voos para Argentina=%d", cont_argentina);
      printf("Quantidade de voos para Brasil=%d", cont_brasil);
      printf("Quantidade total de voos =%d", cont_argentina + cont_brasil);
      break;
    case 8: // vendas consolidadas
      consolidar(&brasil);
      consolidar(&argentina);

      break;
    case 0:
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
  }

  return 0;
}
