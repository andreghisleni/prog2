/*

2) Elabore um programa em C que implemente uma função que realize a ordenação dos valores de 3 variáveis declaradas no programa principal e retorne a media simples dos 3 valores no retorno da função.

*/

#include <stdio.h>

float ordenaTresValores(int *a, int *b, int *c){
    int aux;
    float media;
    
    if(*a > *b){
        aux = *a;
        *a = *b;
        *b = aux;
    }
    
    if(*a > *c){
        aux = *a;
        *a = *c;
        *c = aux;
    }
    
    if(*b > *c){
        aux = *b;
        *b = *c;
        *c = aux;
    }
    
    media = (*a + *b + *c) / 3.0;
    
    return media;
}
void main(){
  int a = 7, b = 3, c = 5;

  printf("\n\nAntes da ordenação: a = %d, b = %d, c = %d", a, b, c);

  printf("\n\nMédia: %.2f", ordenaTresValores(&a, &b, &c));

  printf("\n\nDepois da ordenação: a = %d, b = %d, c = %d", a, b, c);

}