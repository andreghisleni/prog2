/**
  4) Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe pontos tridimensionais (com valores para x, y e z) que devem preencher uma matriz quadrada de 2 x 2;
    Cada ponto informado pelo usuário deve ser armazenado em uma única posição (linha, coluna) da matriz;
    Após finalizar a leitura da matriz, salve os pontos da diagonal principal da matriz em uma lista encadeada;
    Implemente uma subrotina que receba a lista encadeada como parâmetro e retorne uma struct com: a soma dos valores de x e a multiplicação dos valores de y dos pontos tridimensionais armazenados na lista encadeada;  
    Antes de encerrar, o programa principal deve imprimir os pontos da matriz, os pontos da lista encadeada e os campos da struct que retornou da subrotina com os cálculos;
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para pontos tridimensionais
typedef struct Ponto3D {
    double x;
    double y;
    double z;
} Ponto3D;

// Definição da estrutura para um nó da lista encadeada
typedef struct Nodo {
    Ponto3D ponto;
    struct Nodo* proximo;
} Nodo;

// Função para inserir um nó na lista encadeada
Nodo* inserirNodo(Nodo* lista, Ponto3D ponto) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novoNodo->ponto = ponto;
    novoNodo->proximo = lista;
    return novoNodo;
}

// Função para calcular a soma dos valores de x e a multiplicação dos valores de y dos pontos na lista encadeada
struct CalculoResult {
    double somaX;
    double multiplicacaoY;
};

struct CalculoResult calcularLista(Nodo* lista) {
    struct CalculoResult resultado = {0.0, 1.0};

    Nodo* atual = lista;
    while (atual != NULL) {
        resultado.somaX += atual->ponto.x;
        resultado.multiplicacaoY *= atual->ponto.y;
        atual = atual->proximo;
    }

    return resultado;
}

int main() {
    Ponto3D matriz[2][2];
    Nodo* diagonalPrincipal = NULL;

    // Preenchendo a matriz 2x2 com pontos tridimensionais
    printf("Digite os valores para preencher a matriz 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite o valor de x para a posição (%d, %d): ", i, j);
            scanf("%lf", &matriz[i][j].x);
            printf("Digite o valor de y para a posição (%d, %d): ", i, j);
            scanf("%lf", &matriz[i][j].y);
            printf("Digite o valor de z para a posição (%d, %d): ", i, j);
            scanf("%lf", &matriz[i][j].z);

            // Adicionar pontos da diagonal principal à lista
            if (i == j) {
                diagonalPrincipal = inserirNodo(diagonalPrincipal, matriz[i][j]);
            }
        }
    }

    // Calcular a soma de x e a multiplicação de y dos pontos na lista
    struct CalculoResult resultado = calcularLista(diagonalPrincipal);

    // Exibir pontos da matriz
    printf("Pontos na matriz 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Ponto (%d, %d): (x=%.2lf, y=%.2lf, z=%.2lf)\n", i, j, matriz[i][j].x, matriz[i][j].y, matriz[i][j].z);
        }
    }

    // Exibir pontos da lista encadeada
    printf("\nPontos na lista encadeada (diagonal principal):\n");
    Nodo* atual = diagonalPrincipal;
    while (atual != NULL) {
        printf("(x=%.2lf, y=%.2lf, z=%.2lf)\n", atual->ponto.x, atual->ponto.y, atual->ponto.z);
        atual = atual->proximo;
    }

    // Exibir cálculos
    printf("\nSoma dos valores de x na diagonal principal: %.2lf\n", resultado.somaX);
    printf("Multiplicação dos valores de y na diagonal principal: %.2lf\n", resultado.multiplicacaoY);

    // Liberar a memória alocada para a lista encadeada
    while (diagonalPrincipal != NULL) {
        Nodo* temp = diagonalPrincipal;
        diagonalPrincipal = diagonalPrincipal->proximo;
        free(temp);
    }

    return 0;
}
