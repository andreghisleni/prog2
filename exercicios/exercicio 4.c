/**
  4) Construa um programa em C que cumpra os seguintes requisitos:
    Leia 6 números informados pelo usuário, guardando os 3 primeiros em um vetor e os 3 últimos em um outro vetor; 
    Tenha uma subrotina que receba os vetores com os números informados pelo usuário e retorne um vetor unificado, com os 6 números; 
    No programa principal, imprima os valores salvos nos vetores originais e no vetor retornado pela subrotina. 
*/

#include <stdio.h>

void unificarVetores(int *vetor1, int *vetor2, int *vetor3){
  for(int i = 0; i < 3; i++){
    vetor3[i] = vetor1[i];
    vetor3[i + 3] = vetor2[i];
  }
}

void mostrarVetor(int *vetor, int tamanho_do_vetor){
  for(int i = 0; i < tamanho_do_vetor; i++){
    printf("%d ", vetor[i]);
  }
}

void main(){
  int vetor1[3], vetor2[3], vetor3[6];

  printf("Digite 3 números para o vetor 1: ");
  scanf("%d %d %d", &vetor1[0], &vetor1[1], &vetor1[2]);

  printf("Digite 3 números para o vetor 2: ");
  scanf("%d %d %d", &vetor2[0], &vetor2[1], &vetor2[2]);

  unificarVetores(&vetor1, &vetor2, &vetor3);

  printf("\n\nVetor 1: ");
  mostrarVetor(vetor1, 3);

  printf("\n\nVetor 2: ");
  mostrarVetor(vetor2, 3);

  printf("\n\nVetor 3: ");
  mostrarVetor(vetor3, 6);

}