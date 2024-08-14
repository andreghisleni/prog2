/**
  3)  Construa um programa em C que cumpra os seguintes requisitos:
    O programa principal deve ler 10 números inteiros positivos em armazená-los em um vetor;
    Após o preenchimento do vetor, o mesmo deve ser enviado para uma função que retorne uma lista duplamente encadeada contendo os números pares que estavam armazenados no vetor;
    O programa principal deve mostrar o conteúdo da lista duplamente encadeada, que retornou da função, antes de encerrar o programa;

*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da lista duplamente encadeada
typedef struct Nodo {
    int valor;
    struct Nodo* proximo;
    struct Nodo* anterior;
} Nodo;

// Função para inserir um número par em uma lista duplamente encadeada
Nodo* inserirNumeroPar(Nodo* lista, int numero) {
    if (numero % 2 == 0) {
        Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
        if (novoNodo == NULL) {
            printf("Erro na alocação de memória.\n");
            exit(1);
        }
        novoNodo->valor = numero;
        novoNodo->proximo = NULL;
        novoNodo->anterior = NULL;

        if (lista == NULL) {
            return novoNodo;
        }

        Nodo* atual = lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNodo;
        novoNodo->anterior = atual;
    }
    return lista;
}

// Função para exibir o conteúdo da lista duplamente encadeada
void exibirLista(Nodo* lista) {
    printf("Conteúdo da lista duplamente encadeada:\n");
    Nodo* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int vetor[10];
    Nodo* lista = NULL;

    printf("Informe 10 números inteiros positivos:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++) {
        lista = inserirNumeroPar(lista, vetor[i]);
    }

    // Exibe o conteúdo da lista duplamente encadeada
    exibirLista(lista);

    // Libera a memória alocada para a lista encadeada
    Nodo* atual = lista;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
