/**
  1. 2023-2 Redimensionamento de vetores de structs
Implemente o programa C, sem usar a função REALOC, sem usar Break (Com exceção do Switch/Case) e sem usar variáveis globais, que atenda aos requisitos abaixo:
(1 ponto) No programa principal, solicite ao usuário que informe dados de temperatura de um equipamento, contendo as seguintes informações: código do equipamento e temperatura. O sistema só deve parar de armazenar as informações quando o usuário informar o código do equipamento = 0 ou negativo;
(2 pontos) As 2 informações digitadas pelo usuário, que compõem cada leitura, devem ser armazenadas em um vetor de Structs de 10 posições;
(5 pontos) Para otimizar a memória do sistema, o vetor que armazena os dados das leituras deve crescer de 10 em 10 espaços de armazenamento (posições), quando for detectado que o mesmo está chegando no seu limite. Para isso o programa principal deve chamar uma subrotina/ função passando o vetor atual e a ocupação atual do mesmo como parâmetros e retornar o novo vetor com maior capacidade;

(2 pontos)Além de alocar um vetor maior, a função tem que prever na sua lógica de programação a cópia dos dados do vetor recebido como parâmetro para o novo vetor alocado com mais espaço, antes retornar o mesmo para o programa principal.


*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para armazenar os dados de temperatura
struct Equipamento
{
    int codigo;
    float temperatura;
};

// Função para redimensionar o vetor
struct Equipamento *redimensionarVetor(struct Equipamento *vetor, int *tamanhoAtual)
{
    *tamanhoAtual += 10;
    struct Equipamento *novoVetor = (struct Equipamento *)malloc(*tamanhoAtual * sizeof(struct Equipamento));

    if (novoVetor == NULL)
    {
        printf("Erro ao alocar memória para o novo vetor.\n");
        exit(1);
    }

    // Copia os dados do vetor antigo para o novo vetor
    for (int i = 0; i < (*tamanhoAtual - 10); i++)
    {
        novoVetor[i] = vetor[i];
    }

    free(vetor);

    return novoVetor;
}

int main()
{
    int tamanhoVetor = 10;
    int ocupacao = 0;
    struct Equipamento *vetor = (struct Equipamento *)malloc(tamanhoVetor * sizeof(struct Equipamento));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }

    int codigoEquipamento = 1;
    float temperaturaEquipamento;

    printf("Informe o código do equipamento e a temperatura (para parar, digite código <= 0):\n");

    while (codigoEquipamento > 0)
    {
        printf("Código: \n");
        scanf("%d", &codigoEquipamento);

        if (codigoEquipamento > 0)
        {

            printf("Temperatura: \n");
            scanf("%f", &temperaturaEquipamento);

            vetor[ocupacao].codigo = codigoEquipamento;
            vetor[ocupacao].temperatura = temperaturaEquipamento;
            ocupacao++;

            if (ocupacao == tamanhoVetor)
            {
                // Redimensionar o vetor
                vetor = redimensionarVetor(vetor, &tamanhoVetor);
            }
        }
    }

    // Imprimir os dados armazenados
    printf("Dados de temperatura do equipamento:\n");
    for (int i = 0; i < ocupacao; i++)
    {
        printf("Código: %d, Temperatura: %.2f\n", vetor[i].codigo, vetor[i].temperatura);
    }

    // Liberar a memória alocada
    free(vetor);

    return 0;
}
