/**
  2)  Construa um programa em C que cumpra os seguintes requisitos:
    O programa principal deve apresentar um menu com as seguintes opções (nova leitura, consultar e sair);
    Opção novo = solicite ao usuário que informe dados de leitura de um data logger contendo as seguintes informações: código do equipamento, temperatura, velocidade do vento, umidade relativa do ar e salve os dados (4 informações) em um único nó de uma lista encadeada;
    Opção consultar =  solicite ao usuário que informe o código do equipamento e apresente na tela os dados de todas as leituras salvas na lista para o código de equipamento informado;
    Opção sair = encerra o programa;
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para armazenar as informações de leitura
typedef struct Leitura {
int codigoEquipamento;
float temperatura;
float velocidadeVento;
float umidadeRelativaAr;
struct Leitura* proxima;
} Leitura;

// Função para inserir uma nova leitura na lista encadeada
Leitura* inserirLeitura(Leitura* inicio, int codigoEquipamento, float temperatura, float velocidadeVento, float umidadeRelativaAr) {
  Leitura* novaLeitura = (Leitura*)malloc(sizeof(Leitura));
  if (novaLeitura == NULL) {
      printf("Erro na alocação de memória.\n");
      exit(1);
  }
  novaLeitura->codigoEquipamento = codigoEquipamento;
  novaLeitura->temperatura = temperatura;
  novaLeitura->velocidadeVento = velocidadeVento;
  novaLeitura->umidadeRelativaAr = umidadeRelativaAr;
  novaLeitura->proxima = inicio;
  return novaLeitura;
}

// Função para consultar as leituras para um código de equipamento específico
void consultarLeituras(Leitura* inicio, int codigoEquipamento) {
  Leitura* atual = inicio;
  int encontradas = 0;

  printf("Leituras para o código de equipamento %d:\n", codigoEquipamento);
  while (atual != NULL) {
    if (atual->codigoEquipamento == codigoEquipamento) {
      printf("Temperatura: %.2f, Velocidade do Vento: %.2f, Umidade Relativa do Ar: %.2f\n", atual->temperatura, atual->velocidadeVento, atual->umidadeRelativaAr);
      encontradas = 1;
    }
    atual = atual->proxima;
  }

  if (!encontradas) {
    printf("Nenhuma leitura encontrada para o código de equipamento %d.\n", codigoEquipamento);
  }
}

// Função para liberar a memória alocada para a lista encadeada
void liberarMemoria(Leitura* inicio) {
  Leitura* atual = inicio;
  while (atual != NULL) {
      Leitura* temp = atual;
      atual = atual->proxima;
      free(temp);
  }
}

int main() {
  Leitura* inicio = NULL;
  int escolha;

  do {
    printf("Menu:\n");
    printf("1. Nova Leitura\n");
    printf("2. Consultar\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
      case 1:
        int codigoEquipamento;
        float temperatura, velocidadeVento, umidadeRelativaAr;

        printf("Informe o código do equipamento: ");
        scanf("%d", &codigoEquipamento);
        printf("Informe a temperatura: ");
        scanf("%f", &temperatura);
        printf("Informe a velocidade do vento: ");
        scanf("%f", &velocidadeVento);
        printf("Informe a umidade relativa do ar: ");
        scanf("%f", &umidadeRelativaAr);

        inicio = inserirLeitura(inicio, codigoEquipamento, temperatura, velocidadeVento, umidadeRelativaAr);
        break;

      case 2:
        int codigoConsulta;

        printf("Informe o código do equipamento para consulta: ");
        scanf("%d", &codigoConsulta);
        consultarLeituras(inicio, codigoConsulta);
        break;

      case 3:
        // Encerra o programa e libera a memória alocada
        liberarMemoria(inicio);
        break;

      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  } while (escolha != 3);

  return 0;
}
