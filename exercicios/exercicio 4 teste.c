/**
  4) Construa um programa em C que cumpra os seguintes requisitos:
    Leia 6 números informados pelo usuário, guardando os 3 primeiros em um vetor e os 3 últimos em um outro vetor; 
    Tenha uma subrotina que receba os vetores com os números informados pelo usuário e retorne um vetor unificado, com os 6 números; 
    No programa principal, imprima os valores salvos nos vetores originais e no vetor retornado pela subrotina. 
*/

#include <stdio.h>



void mostrarVetor(int *vetor, int tamanho_do_vetor){
  for(int i = 0; i < tamanho_do_vetor; i++){
    printf("%d ", vetor[i]);
  }
}

int * join(int *vetor1, int *vetor2){
  int vetor3[6];

  for(int i = 0; i < 3; i++){
    vetor3[i] = vetor1[i];
    vetor3[i + 3] = vetor2[i];
  }

  return vetor3;
}

void main(){
  // int vetor1[3], vetor2[3];

  // printf("Digite 3 números para o vetor 1: ");
  // scanf("%d %d %d", &vetor1[0], &vetor1[1], &vetor1[2]);

  // printf("Digite 3 números para o vetor 2: ");
  // scanf("%d %d %d", &vetor2[0], &vetor2[1], &vetor2[2]);

  int vetor1[] = {1, 2, 3};
  int vetor2[] = {4, 5, 6};

  printf("mostrar ponteiro do vetor1: %p\n", vetor1);
  printf("mostrar ponteiro do vetor1: %p\n", &vetor1);

  int * vetor3 = join(vetor1, vetor2);

  printf("\n\nVetor 1: ");
  mostrarVetor(vetor1, 3);

  printf("\n\nVetor 2: ");
  mostrarVetor(vetor2, 3);

  printf("\n\nVetor 3: ");
  mostrarVetor(vetor3, 6);

}