/**
    1) Construa um programa em C que cumpra os seguintes requisitos:

        No programa principal, solicite ao usuário que informe uma série de componentes contendo as seguintes informações (código e número de série) e armazene os mesmos em um struct alocado dinamicamente;
        Crie uma subrotina que receba esse struct e inclua o mesmo em uma  lista duplamente encadeada.
        O programa deve continuar armazenando os componentes, utilizando a subrotina, até que o número zero seja informado para o código de algum deles;
        Antes de encerrar o programa, imprima na tela os dados de todos os componentes que foram armazenados, do primeiro para último e do último para o primeiro;
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do componente
struct Componente
{
    int codigo;
    int numeroSerie;
    struct Componente *proximo;
    struct Componente *anterior;
};

// Estrutura para armazenar a lista e referências para o primeiro e último nós
struct ListaComponentes
{
    struct Componente *primeiro;
    struct Componente *ultimo;
};

// Função para inicializar a lista de componentes
void inicializarLista(struct ListaComponentes *lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

// Função para adicionar um componente à lista duplamente encadeada
void adicionarComponente(struct ListaComponentes *lista, int codigo, int numeroSerie)
{
    struct Componente *novoComponente = (struct Componente *)malloc(sizeof(struct Componente));
    novoComponente->codigo = codigo;
    novoComponente->numeroSerie = numeroSerie;
    novoComponente->proximo = NULL;

    if (lista->primeiro == NULL)
    {
        novoComponente->anterior = NULL;
        lista->primeiro = novoComponente;
    }
    else
    {
        novoComponente->anterior = lista->ultimo;
        lista->ultimo->proximo = novoComponente;
    }

    lista->ultimo = novoComponente;
}

// Função para imprimir os componentes da lista do primeiro para o último
void imprimirListaDoInicioAoFim(struct ListaComponentes lista)
{
    printf("Componentes do primeiro para o último:\n");
    struct Componente *atual = lista.primeiro;
    while (atual != NULL)
    {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para imprimir os componentes da lista do último para o primeiro
void imprimirListaDoFimAoInicio(struct ListaComponentes lista)
{
    if (lista.ultimo == NULL)
    {
        return;
    }

    printf("Componentes do último para o primeiro:\n");
    struct Componente *atual = lista.ultimo;
    while (atual != NULL)
    {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->anterior;
    }
    printf("\n");
}

int main()
{
    struct ListaComponentes lista;
    inicializarLista(&lista);
    int codigo, numeroSerie;

    printf("Informe o código e número de série do componente (ou digite 0 para encerrar):\n");
    do
    {
        printf("Código: ");
        scanf("%d", &codigo);

        if (codigo != 0)
        {
            printf("Número de Série: ");
            scanf("%d", &numeroSerie);

            adicionarComponente(&lista, codigo, numeroSerie);
        }
    } while (codigo != 0);

    imprimirListaDoInicioAoFim(lista);
    imprimirListaDoFimAoInicio(lista);

    // Liberar a memória alocada para os componentes
    struct Componente *atual = lista.primeiro;
    while (atual != NULL)
    {
        struct Componente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
