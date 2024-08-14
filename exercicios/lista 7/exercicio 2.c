/**
  2)  Construa um programa em C que cumpra os seguintes requisitos:
    O programa principal deve apresentar um menu com as seguintes opções (nova leitura, consultar e sair);
    Opção novo = solicite ao usuário que informe dados de leitura de um data logger contendo as seguintes informações: código do equipamento, temperatura, velocidade do vento, umidade relativa do ar e salve os dados (4 informações) em um único nó de uma lista duplamente encadeada;
    Opção consultar =  solicite ao usuário que informe o código do equipamento e apresente na tela os dados de todas as leituras salvas na lista para o código de equipamento informado, sendo que a consulta deve iniciar o último para o primeiro elemento da lista;
    Opção sair = encerra o programa;
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para leitura do data logger
typedef struct Leitura {
    int codigoEquipamento;
    float temperatura;
    float velocidadeVento;
    float umidadeRelativaAr;
    struct Leitura* proxima;
    struct Leitura* anterior;
} Leitura;

// Função para inserir uma nova leitura no final da lista duplamente encadeada
Leitura* inserirLeitura(Leitura* lista, int codigoEquipamento, float temperatura, float velocidadeVento, float umidadeRelativaAr) {
    Leitura* novaLeitura = (Leitura*)malloc(sizeof(Leitura));
    if (novaLeitura == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novaLeitura->codigoEquipamento = codigoEquipamento;
    novaLeitura->temperatura = temperatura;
    novaLeitura->velocidadeVento = velocidadeVento;
    novaLeitura->umidadeRelativaAr = umidadeRelativaAr;
    novaLeitura->proxima = NULL;
    novaLeitura->anterior = NULL;

    if (lista == NULL) {
        return novaLeitura;
    }

    Leitura* atual = lista;
    while (atual->proxima != NULL) {
        atual = atual->proxima;
    }
    atual->proxima = novaLeitura;
    novaLeitura->anterior = atual;

    return lista;
}

// Função para consultar as leituras para um código de equipamento específico (do último para o primeiro)
void consultarLeituras(Leitura* lista, int codigoEquipamento) {
    Leitura* atual = lista;
    while (atual != NULL) {
        if (atual->codigoEquipamento == codigoEquipamento) {
            printf("Código do Equipamento: %d\n", atual->codigoEquipamento);
            printf("Temperatura: %.2f\n", atual->temperatura);
            printf("Velocidade do Vento: %.2f\n", atual->velocidadeVento);
            printf("Umidade Relativa do Ar: %.2f\n", atual->umidadeRelativaAr);
            printf("----------\n");
        }
        atual = atual->anterior;
    }
}

// Função para liberar a memória alocada para a lista encadeada
void liberarMemoria(Leitura* lista) {
    Leitura* atual = lista;
    while (atual != NULL) {
        Leitura* temp = atual;
        atual = atual->proxima;
        free(temp);
    }
}

int main() {
    Leitura* lista = NULL;
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

                lista = inserirLeitura(lista, codigoEquipamento, temperatura, velocidadeVento, umidadeRelativaAr);
                break;

            case 2:
                int codigoConsulta;

                printf("Informe o código do equipamento para consulta: ");
                scanf("%d", &codigoConsulta);
                consultarLeituras(lista, codigoConsulta);
                break;

            case 3:
                // Encerra o programa e libera a memória alocada
                liberarMemoria(lista);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}
