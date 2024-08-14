/**

  Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário quantos números ele quer informar;
    No programa principal, aloque um vetor para armazenar quantidade de números que o usuário informou na solicitação anterior;
    No programa principal, solicite ao usuário que informe os números (conforme a quantidade que ele mesmo indicou) e armazene os mesmos no vetor;
    Tenha uma sobrotina que receba o vetor com os números informados pelo usuário e retorne um novo vetor com a soma dos números pares, a soma dos ímpares, o maior par e o maior ímpar (caso não existam números pares ou ímpares no vetor informado pelo usuário, considere o valor zero);
    No programa principal, imprima os valores do vetor original e do vetor que retornou da subrotina, APÓS a chamada da subrotina;

*/

#include <stdio.h>
#include <stdlib.h>

int* calcularSomasEMaiores(int *vetor, int tamanho) {
    int *resultados = (int *)malloc(4 * sizeof(int));
    if (resultados == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    int somaPares = 0;
    int somaImpares = 0;
    int maiorPar = 0;
    int maiorImpar = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            somaPares += vetor[i];
            if (vetor[i] > maiorPar) {
                maiorPar = vetor[i];
            }
        } else {
            somaImpares += vetor[i];
            if (vetor[i] > maiorImpar) {
                maiorImpar = vetor[i];
            }
        }
    }

    resultados[0] = somaPares;
    resultados[1] = somaImpares;
    resultados[2] = maiorPar;
    resultados[3] = maiorImpar;

    return resultados;
}

int main() {
    int quantidadeNumeros;

    printf("Quantos numeros voce quer informar? ");
    scanf("%d", &quantidadeNumeros);

    int *vetorNumeros = (int *)malloc(quantidadeNumeros * sizeof(int));

    if (vetorNumeros == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < quantidadeNumeros; i++) {
        printf("Informe o numero %d: ", i + 1);
        scanf("%d", &vetorNumeros[i]);
    }

    int *resultados = calcularSomasEMaiores(vetorNumeros, quantidadeNumeros);

    printf("\nValores do vetor original:\n");
    for (int i = 0; i < quantidadeNumeros; i++) {
        printf("%d ", vetorNumeros[i]);
    }

    printf("\n\nValores do vetor retornado pela subrotina:\n");
    printf("Soma dos pares: %d\n", resultados[0]);
    printf("Soma dos impares: %d\n", resultados[1]);
    printf("Maior par: %d\n", resultados[2]);
    printf("Maior impar: %d\n", resultados[3]);

    free(vetorNumeros);
    free(resultados);

    return 0;
}
