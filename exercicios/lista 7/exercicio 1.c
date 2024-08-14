/**
  1) Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe uma série de componentes contendo as seguintes informações (código e número de série) e armazene os mesmos em uma lista duplamente encadeada;
    O programa deve continuar armazenando os componentes até que o número zero seja informado para o código de algum deles;
    Antes de encerrar o programa, imprima na tela os dados de todos os componentes que foram armazenados, do primeiro para último e do último para o primeiro;
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para o componente
typedef struct Componente {
    int codigo;
    int numeroSerie;
    struct Componente* proximo;
    struct Componente* anterior;
} Componente;

// Função para inserir um componente no final da lista duplamente encadeada
Componente* inserirComponente(Componente* lista, int codigo, int numeroSerie) {
    Componente* novoComponente = (Componente*)malloc(sizeof(Componente));
    if (novoComponente == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novoComponente->codigo = codigo;
    novoComponente->numeroSerie = numeroSerie;
    novoComponente->proximo = NULL;
    novoComponente->anterior = NULL;

    if (lista == NULL) {
        return novoComponente;
    }

    Componente* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoComponente;
    novoComponente->anterior = atual;

    return lista;
}

// Função para imprimir os dados dos componentes do primeiro para o último
void imprimirComponentesDoPrimeiro(Componente* lista) {
    printf("Componentes armazenados (do primeiro para o último):\n");
    Componente* atual = lista;
    while (atual != NULL) {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->proximo;
    }
}

// Função para imprimir os dados dos componentes do último para o primeiro
void imprimirComponentesDoUltimo(Componente* lista) {
    printf("Componentes armazenados (do último para o primeiro):\n");
    Componente* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    while (atual != NULL) {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->anterior;
    }
}

int main() {
    Componente* lista = NULL;
    int codigo, numeroSerie;

    printf("Informe o código e número de série do componente (ou digite 0 para encerrar):\n");

    do {
        printf("Código: ");
        scanf("%d", &codigo);

        if(codigo != 0) {
            printf("Número de Série: ");
            scanf("%d", &numeroSerie);

            lista = inserirComponente(lista, codigo, numeroSerie);
        }

    } while (codigo != 0);

    // Imprime os componentes armazenados do primeiro para o último
    imprimirComponentesDoPrimeiro(lista);

    // Imprime os componentes armazenados do último para o primeiro
    imprimirComponentesDoUltimo(lista);

    // Libera a memória alocada para os componentes
    Componente* atual = lista;
    while (atual != NULL) {
        Componente* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
