/**
  1) Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe uma série de componentes contendo as seguintes informações (código e número de série) e armazene os mesmos em uma lista encadeada;
    O programa deve continuar armazenando os componentes até que o número zero seja informado para o código de algum deles;
    Antes de encerrar o programa, imprima na tela os dados de todos os componentes que foram armazenados;
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do componente
typedef struct Componente {
    int codigo;
    int numeroSerie;
    struct Componente* proximo;
} Componente;

// Função para imprimir os dados dos componentes na lista encadeada
void imprimirComponentes(Componente* inicio) {
    Componente* atual = inicio;
    printf("Componentes armazenados:\n");
    while (atual != NULL) {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->proximo;
    }
}

int main() {
    Componente* inicio = NULL;
    Componente* novoComponente;

    int codigo, numeroSerie;

    printf("Informe o código e número de série do componente (ou digite 0 para encerrar):\n");

    while (codigo != 0) {
        printf("Código: ");
        scanf("%d", &codigo);

        if (codigo != 0) {

          printf("Número de Série: ");
          scanf("%d", &numeroSerie);

          novoComponente = (Componente*)malloc(sizeof(Componente));
          if (novoComponente == NULL) {
              printf("Erro na alocação de memória.\n");
              return 1;
          }

          novoComponente->codigo = codigo;
          novoComponente->numeroSerie = numeroSerie;
          novoComponente->proximo = inicio;
          inicio = novoComponente;
        }
    }

    // Imprime os componentes armazenados
    imprimirComponentes(inicio);

    // Libera a memória alocada para os componentes
    Componente* atual = inicio;
    while (atual != NULL) {
        Componente* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
