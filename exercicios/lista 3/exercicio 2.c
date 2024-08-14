/**
  2) Construa um programa em C que cumpra os seguintes requisitos:
  No programa principal, solicite ao usuário quantos números ele quer informar;
  No programa principal, aloque um vetor para armazenar quantidade de números que o usuário informou na solicitação anterior;
  No programa principal, solicite ao usuário que informe os números (conforme a quantidade que ele mesmo indicou) e armazene os mesmos no vetor;
  Tenha uma sobrotina que receba o vetor com os números informados pelo usuário e retorne um  outro vetor contendo o maior e o menor números encontrados no vetor enviado (caso o usuário só tenha informado um número, retorne as duas posições do vetor com este mesmo número);
  No programa principal, imprima os valores do vetor original e do vetor que retornou da subrotina, APÓS a chamada da subrotina;

*/

#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior e o menor número em um vetor
void encontrarMaiorEMenor(int *numeros, int tamanho, int *resultado) {
    if (tamanho == 0) {
        resultado[0] = resultado[1] = 0; // Vetor vazio, definindo ambos como 0
        return;
    }

    int maior = numeros[0];
    int menor = numeros[0];

    for (int i = 1; i < tamanho; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    resultado[0] = menor;
    resultado[1] = maior;
}

int main() {
    int quantidade;

    printf("Quantos numeros voce quer informar? ");
    scanf("%d", &quantidade);

    int *numeros = (int *)malloc(quantidade * sizeof(int));

    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("Informe o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int resultado[2];
    encontrarMaiorEMenor(numeros, quantidade, resultado);

    printf("\nNumeros informados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\nMaior numero: %d\n", resultado[1]);
    printf("Menor numero: %d\n", resultado[0]);

    free(numeros);

    return 0;
}
