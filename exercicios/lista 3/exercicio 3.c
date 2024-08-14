/*

  Construa um programa em C que cumpra os seguintes requisitos:
  No programa principal, solicite ao usuário quantos números ele quer informar;
  No programa principal, aloque um vetor para armazenar quantidade de números que o usuário informou na solicitação anterior;
  No programa principal, solicite ao usuário que informe os números (conforme a quantidade que ele mesmo indicou) e armazene os mesmos no vetor;
  Tenha uma sobrotina que receba o vetor com os números informados pelo usuário e retorne um novo vetor com os números na ordem inversa;
  No programa principal, imprima os valores do vetor original e do vetor que retornou da subrotina, APÓS a chamada da subrotina;

*/

#include <stdio.h>
#include <stdlib.h>

// Função para inverter os elementos de um vetor
int* inverterVetor(int* vetor, int tamanho) {
    int* vetorInvertido = (int*)malloc(tamanho * sizeof(int));

    if (vetorInvertido == NULL) {
        printf("Erro ao alocar memória para o vetor invertido.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        vetorInvertido[i] = vetor[tamanho - 1 - i];
    }

    return vetorInvertido;
}

int main() {
    int quantidade;

    printf("Quantos numeros voce quer informar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida. O programa sera encerrado.\n");
        return 1;
    }

    int* vetor = (int*)malloc(quantidade * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    printf("Informe os numeros:\n");
    for (int i = 0; i < quantidade; i++) {
        scanf("%d", &vetor[i]);
    }

    int* vetorInvertido = inverterVetor(vetor, quantidade);

    printf("\nVetor original: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nVetor invertido: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetorInvertido[i]);
    }

    printf("\n");

    // Liberar a memória alocada
    free(vetor);
    free(vetorInvertido);

    return 0;
}
