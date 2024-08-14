/**
  3.B)  Construa um programa em C que cumpra os seguintes requisitos:
    O programa principal deve ler 10 números inteiros positivos em armazená-los em um vetor;
    Após o preenchimento do vetor, o mesmo deve ser enviado para uma função que retorne uma lista duplamente encadeada contendo os números pares e outra lista duplamente encadeada com os números ímpares que estavam armazenados no vetor. É sugerido que seja criado um struct que armazene os ponteiros de controle de cada lista e retorne o mesmo para o programa principal, uma vez que as funções só podem retornar um valor;
    O programa principal deve mostrar o conteúdo das  duas listas duplamente encadeadas, que retornaram da função, antes de encerrar o programa;

*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da lista duplamente encadeada
typedef struct Nodo {
    int valor;
    struct Nodo* proximo;
    struct Nodo* anterior;
} Nodo;

// Definição da estrutura para armazenar as listas duplamente encadeadas
typedef struct Listas {
    Nodo* pares;
    Nodo* impares;
} Listas;

// Função para inicializar as duas listas
Listas inicializarListas() {
    Listas listas;
    listas.pares = NULL;
    listas.impares = NULL;
    return listas;
}

// Função para inserir um número em uma das listas com base em sua paridade
void inserirNumero(Listas* listas, int numero) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novoNodo->valor = numero;
    novoNodo->proximo = NULL;
    novoNodo->anterior = NULL;

    if (numero % 2 == 0) {
        if (listas->pares == NULL) {
            listas->pares = novoNodo;
        } else {
            Nodo* atual = listas->pares;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoNodo;
            novoNodo->anterior = atual;
        }
    } else {
        if (listas->impares == NULL) {
            listas->impares = novoNodo;
        } else {
            Nodo* atual = listas->impares;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoNodo;
            novoNodo->anterior = atual;
        }
    }
}

// Função para exibir o conteúdo de uma lista duplamente encadeada
void exibirLista(Nodo* lista, const char* nomeLista) {
    printf("Conteúdo da lista %s:\n", nomeLista);
    Nodo* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Listas listas = inicializarListas();
    int vetor[10];

    printf("Informe 10 números inteiros positivos:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++) {
        inserirNumero(&listas, vetor[i]);
    }

    // Exibe o conteúdo das listas duplamente encadeadas
    exibirLista(listas.pares, "pares");
    exibirLista(listas.impares, "ímpares");

    // Libera a memória alocada para as listas encadeadas
    Nodo* atual = listas.pares;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    atual = listas.impares;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}


