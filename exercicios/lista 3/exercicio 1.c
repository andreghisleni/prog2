/**
  1) Construa um programa em C que cumpra os seguintes requisitos:
  No programa principal, solicite ao usuário quantos números ele quer informar;
  No programa principal, aloque um vetor para armazenar quantidade de números que o usuário informou na solicitação anterior;
  No programa principal, solicite ao usuário que informe os números (conforme a quantidade que ele mesmo indicou) e armazene os mesmos no vetor;
  Tenha uma sub-rotina que receba o vetor com os números informados pelo usuário e retorne um  outro vetor contendo os dois (2) maiores números encontrados no vetor enviado (caso o usuário só tenha informado um número, retorne as duas posições do vetor com este mesmo número);
  No programa principal, imprima os valores do vetor original e do vetor que retornou da sub-rotina, APÓS a chamada da sub-rotina;
*/

#include <stdio.h>
#include <stdlib.h>

// Sub-rotina para encontrar os dois maiores números no vetor
void encontrarMaiores(int *vetor, int tamanho, int *maior) {
    maior[0] = maior[1] = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior[0]) {
            maior[1] = maior[0];
            maior[0] = vetor[i];
        } else if (vetor[i] > maior[1]) {
            maior[1] = vetor[i];
        }
    }
}

int main() {
    int quantidade;
    printf("Informe quantos números você quer informar: ");
    scanf("%d", &quantidade);

    // Aloca o vetor dinamicamente
    int *numeros = (int *)malloc(quantidade * sizeof(int));

    printf("Informe os números:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &numeros[i]);
    }

    int maior[2];
    encontrarMaiores(numeros, quantidade, maior);

    printf("Vetor original: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d, ", numeros[i]);
    }
    printf("\n");

    printf("Dois maiores números: %d, %d\n", maior[0], maior[1]);

    // Libera a memória alocada para o vetor
    free(numeros);

    return 0;
}
