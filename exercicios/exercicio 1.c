/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

1) Elabore um programa em C que implemente uma função que realize a troca dos valores de 4 variáveis declaradas no programa principal, conforme o exemplo a seguir:

 X=5, Y= 8 e A=3 e B=2, após a função, X=8, Y=5 e A=2 e B=3.

*******************************************************************************/

#include <stdio.h>

void trocaDoisValores(int *a, int *b){
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;    
}

void main()
{
    printf("Hello World");

    int x = 5, y = 8, a = 3, b = 2;

    printf("\n\nAntes da troca: x = %d, y = %d, a = %d, b = %d", x, y, a, b);
    
    trocaDoisValores(&x, &y);
    trocaDoisValores(&a, &b);

    printf("\n\nDepois da troca: x = %d, y = %d, a = %d, b = %d", x, y, a, b);

}
