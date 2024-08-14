/*

1) Construa um programa em C que cumpra os seguintes requisitos:
Leia 6 números informados pelo usuário em um vetor; 
Tenha uma subrotina que receba o vetor com os números informados pelo usuário e identifique o maior e o menor números encontrados no vetor; 
No programa principal, imprima os valores salvos no vetor original e o maior e menor números identificados na subrotina. 
*/

#include <stdio.h>

void ordenarVetor(int *vetor, int tamanho_do_vetor){
  int aux;
  for(int i = 0; i < tamanho_do_vetor; i++){
    for(int j = 0; j < tamanho_do_vetor; j++){
      if(vetor[i] < vetor[j]){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
}

void mostrarVetor(int *vetor, int tamanho_do_vetor){
  for(int i = 0; i < tamanho_do_vetor; i++){
    printf("%d ", vetor[i]);
  }
}

void main(){
  int vetor[] = {3, 13, 5, 7, 1, 9};
  int tamanho_do_vetor = sizeof(vetor) / sizeof(vetor[0]);

  printf("Sizeof vetor: %id\n", sizeof(vetor));
  printf("Sizeof vetor[0]: %id\n", sizeof(vetor[0]));

  printf("Tamanho do vetor: %d", tamanho_do_vetor);

  printf("\n\nAntes da ordenação: ");
  mostrarVetor(vetor, tamanho_do_vetor);

  ordenarVetor(vetor, tamanho_do_vetor);

  printf("\n\nDepois da ordenação: ");
  mostrarVetor(vetor, tamanho_do_vetor);
}