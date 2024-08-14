/**
  4)  Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe pontos tridimensionais (com valores para x, y e z) que devem preencher uma matriz quadrada de 2 x 2;
    Cada ponto informado pelo usuário deve ser armazenado em uma única posição (linha, coluna) da matriz;
    Após finalizar a leitura da matriz, aloque um vetor dinamicamente para armazenar os pontos da diagonal principal da matriz;
    Implemente uma subrotina que receba o vetor como parâmetro e retorne uma struct com: a soma dos valores de x e a multiplicação dos valores de y dos pontos tridimensionais do vetor;  
    Antes de encerrar, o programa principal deve imprimir os pontos da matriz, os pontos do vetor e os campos da struct que retornou da subrotina;
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um ponto tridimensional
struct Ponto {
    float x;
    float y;
    float z;
};

// Função para calcular a soma dos valores de x e a multiplicação dos valores de y do vetor de pontos
struct Resultado {
    float somaX;
    float multiplicacaoY;
};

struct Resultado calcularResultado(struct Ponto *pontos, int tamanho) {
    struct Resultado resultado;
    resultado.somaX = 0.0;
    resultado.multiplicacaoY = 1.0;

    for (int i = 0; i < tamanho; i++) {
        resultado.somaX += pontos[i].x;
        resultado.multiplicacaoY *= pontos[i].y;
    }

    return resultado;
}

int main() {
    int tamanho = 2;
    struct Ponto matriz[2][2];

    // Preencher a matriz com pontos tridimensionais informados pelo usuário
    printf("Digite os valores para os pontos tridimensionais (x, y, z):\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("Ponto (%d, %d): ", i + 1, j + 1);
            scanf("%f %f %f", &matriz[i][j].x, &matriz[i][j].y, &matriz[i][j].z);
        }
    }

    // Alocar dinamicamente um vetor para armazenar os pontos da diagonal principal
    struct Ponto *diagonal = malloc(tamanho * sizeof(struct Ponto));
    for (int i = 0; i < tamanho; i++) {
        diagonal[i] = matriz[i][i];
    }

    // Calcular o resultado da subrotina
    struct Resultado resultado = calcularResultado(diagonal, tamanho);

    // Imprimir os pontos da matriz
    printf("\nPontos da Matriz:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("(%f, %f, %f) ", matriz[i][j].x, matriz[i][j].y, matriz[i][j].z);
        }
        printf("\n");
    }

    // Imprimir os pontos do vetor
    printf("\nPontos da Diagonal:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%f, %f, %f) ", diagonal[i].x, diagonal[i].y, diagonal[i].z);
    }

    // Imprimir os campos da struct resultado
    printf("\n\nResultado da Subrotina:\n");
    printf("Soma dos valores de x: %f\n", resultado.somaX);
    printf("Multiplicação dos valores de y: %f\n", resultado.multiplicacaoY);

    // Liberar a memória alocada dinamicamente
    free(diagonal);

    return 0;
}
