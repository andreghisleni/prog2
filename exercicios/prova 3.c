/**
 *
 *
  1. 2023-02 Função que recebe lista e retorna 2 vetores.
    Escreva um programa em C (Não pode ser em C++) com os seguintes requisitos:

    1 - (5 pontos) No programa principal, Solicite ao usuário que informe 10 pontos 2D (X e Y) e salvem os mesmos em um lista duplamente encadeada com ponteiros primeiro e último.

    Também no programa principal, implemente a chamada correta para a função do item 2.

    2 - (5 pontos) Implemente uma função que receba a lista duplamente encadeadas com os pontos informados pelo usuário e retorne 2 vetores com seus respectivos tamanhos. Um vetor alocado dinamicamente para os pontos que tenham o X par e um outro vetor alocado dinamicamente para os pontos que tenham o Y par. Oserve que podem haver pontos que tenham o X e o Y pares.

    Os vetores devem ter o tamanho exato da quantidade de pontos que vai armazenar.

    A função deve retornar os 2 vetores e seus respctivos tamanhos em um único struct e pelo return da função.

  IMPORTANTE - Estes itens podem zerar a prova.

  - Só pode usar Break em Switch/ case;

  - Não pode ter laços de repetição infinitos, sem condição de parada booleana;

  - Não pode usar variáveis globais;

  - Não pode haver comentários no código
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>

struct Ponto
{
  int x;
  int y;
};

struct PontoNode
{
  struct Ponto ponto;
  struct PontoNode *anterior;
  struct PontoNode *proximo;
};

struct ListaPontos
{
  struct PontoNode *primeiro;
  struct PontoNode *ultimo;
};

void inicializarLista(struct ListaPontos *lista)
{
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

void adicionarPonto(struct ListaPontos *lista, int x, int y)
{
  struct PontoNode *novoPontoNode = (struct PontoNode *)malloc(sizeof(struct PontoNode));
  novoPontoNode->ponto.x = x;
  novoPontoNode->ponto.y = y;
  novoPontoNode->proximo = NULL;

  if (lista->primeiro == NULL)
  {
    novoPontoNode->anterior = NULL;
    lista->primeiro = novoPontoNode;
  }
  else
  {
    novoPontoNode->anterior = lista->ultimo;
    lista->ultimo->proximo = novoPontoNode;
  }

  lista->ultimo = novoPontoNode;
}

struct Vetores
{
  struct Ponto *vetorX;
  int tamanhoX;
  struct Ponto *vetorY;
  int tamanhoY;
};

struct Vetores separarPontos(struct ListaPontos lista)
{
  int contadorX = 0, contadorY = 0;

  struct PontoNode *atual = lista.primeiro;

  while (atual != NULL)
  {
    if (atual->ponto.x % 2 == 0)
    {
      contadorX++;
    }
    if (atual->ponto.y % 2 == 0)
    {
      contadorY++;
    }
    atual = atual->proximo;
  }

  struct Vetores resultado;
  resultado.vetorX = (struct Ponto *)malloc(contadorX * sizeof(struct Ponto));
  resultado.vetorY = (struct Ponto *)malloc(contadorY * sizeof(struct Ponto));
  resultado.tamanhoX = contadorX;
  resultado.tamanhoY = contadorY;

  atual = lista.primeiro;
  int indexX = 0, indexY = 0;

  while (atual != NULL)
  {
    if (atual->ponto.x % 2 == 0)
    {
      resultado.vetorX[indexX++] = atual->ponto;
    }
    if (atual->ponto.y % 2 == 0)
    {
      resultado.vetorY[indexY++] = atual->ponto;
    }
    atual = atual->proximo;
  }

  return resultado;
}

int main()
{
  struct ListaPontos lista;
  inicializarLista(&lista);

  int x, y;

  printf("Informe 10 pontos 2D (X e Y):\n");
  for (int i = 0; i < 10; ++i)
  {
    printf("Ponto %d - X: ", i + 1);
    scanf("%d", &x);
    printf("Ponto %d - Y: ", i + 1);
    scanf("%d", &y);

    adicionarPonto(&lista, x, y);
  }

  struct Vetores resultado = separarPontos(lista);

  free(resultado.vetorX);
  free(resultado.vetorY);

  struct PontoNode *atual = lista.primeiro;
  while (atual != NULL)
  {
    struct PontoNode *temp = atual;
    atual = atual->proximo;
    free(temp);
  }

  return 0;
}
