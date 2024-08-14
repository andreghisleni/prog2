/*

  Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário quantos números ele quer informar;
    No programa principal, aloque um vetor para armazenar quantidade de números que o usuário informou na solicitação anterior;
    No programa principal, solicite ao usuário que informe os números (conforme a quantidade que ele mesmo indicou) e armazene os mesmos no vetor;
    Tenha uma sobrotina que receba como parâmetros APENAS o vetor com os números informados pelo usuário e seu tamanho, mas que retorne dois (2) vetores, um com os números pares e outro com os números ímpares separados;
    No programa principal, imprima os valores do vetor original e dos vetores que retornara da subrotina, APÓS a chamada da subrotina;

*/

#include <stdio.h>
#include <stdlib.h>

// Função para separar números pares e ímpares
int* separarParesImpares(int *vetor, int tamanho) {
    int tamanhoPares = 0;
    int tamanhoImpares = 0;

    // Contar quantos números pares e ímpares existem no vetor
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            tamanhoPares++;
        } else {
            tamanhoImpares++;
        }
    }

    // Alocar memória para os vetores de pares e ímpares
    int *pares = (int *)malloc(sizeof(int) * (tamanhoPares));
    int *impares = (int *)malloc(sizeof(int) * (tamanhoImpares));

    int indicePares = 0;
    int indiceImpares = 0;

    // Separar os números pares e ímpares nos vetores correspondentes
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            (pares)[indicePares++] = vetor[i];
        } else {
            (impares)[indiceImpares++] = vetor[i];
        }
    }

    int *retorno = (int *)malloc(sizeof(int) * (2+ tamanhoPares+tamanhoImpares));
    retorno[0] = tamanhoPares;
    retorno[1] = tamanhoImpares;

    for (int i = 0; i < tamanhoPares; i++) {
        retorno[2+i] = pares[i];
    }

    for (int i = 0; i < tamanhoImpares; i++) {
        retorno[2+tamanhoPares+i] = impares[i];
    }

    // Liberar a memória alocada para os vetores de pares e ímpares
    free(pares);
    free(impares);

    return retorno;
}

int main() {
    int quantidade;
    
    // Solicitar a quantidade de números ao usuário
    printf("Quantos números você deseja informar? ");
    scanf("%d", &quantidade);

    // Alocar memória para o vetor
    int *vetor = (int *)malloc(sizeof(int) * quantidade);

    // Solicitar os números ao usuário e armazená-los no vetor
    for (int i = 0; i < quantidade; i++) {
        printf("Informe o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Chamada da subrotina para separar os números pares e ímpares
    int *resultados = separarParesImpares(vetor, quantidade);

    // Imprimir os valores dos vetores
    printf("\nVetor Original: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nVetor de Pares: ");
    for (int i = 0; i < resultados[0]; i++) {
        printf("%d ", resultados[2+i]);
    }

    printf("\nVetor de Ímpares: ");
    for (int i = 0; i < resultados[1]; i++) {
        printf("%d ", resultados[2+resultados[0]+i]);
    }

    // Liberar a memória alocada
    free(vetor);
    // free(resultados[2]);
    // free(resultados[3]);
    free(resultados);

    return 0;
}
