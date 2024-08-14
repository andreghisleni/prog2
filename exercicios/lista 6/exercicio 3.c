/**
  3)  Construa um programa em C que cumpra os seguintes requisitos:
  No programa principal, solicite ao usuário que informe dados de alunos para seleção de uma vaga para bolsa de pesquisa, contendo as seguintes informações: matricula, nome, semestre, conhecimento na área de programação em C (alta, media ou baixa);
  As 4 informações devem ser armazenadas em uma única estrutura chamada candidato e enviada como parâmetro para um função de armazenamento;
  A função de armazenamento deve manter e retornar um estrutura com 3 listas encadeadas distintas, onde cada lista armazena os candidatos separados por conhecimento na área de programação;
  O sistema só deve parar de solicitar as informações de candidatos quando o usuário informar o código da matrícula = 0;
  O programa principal deve mostrar os candidatos armazenados em cada lista antes de encerrar;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações do candidato
typedef struct Candidato {
    int matricula;
    char nome[50];
    int semestre;
    char conhecimento[10];
    struct Candidato* proximo;
} Candidato;

// Função para inserir um candidato em uma lista encadeada com base no conhecimento
Candidato* inserirCandidato(Candidato* lista, int matricula, const char* nome, int semestre, const char* conhecimento) {
    Candidato* novoCandidato = (Candidato*)malloc(sizeof(Candidato));
    if (novoCandidato == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    novoCandidato->matricula = matricula;
    strcpy(novoCandidato->nome, nome);
    novoCandidato->semestre = semestre;
    strcpy(novoCandidato->conhecimento, conhecimento);
    novoCandidato->proximo = lista;
    return novoCandidato;
}

// Função para exibir a lista de candidatos
void exibirCandidatos(Candidato* lista) {
    Candidato* atual = lista;

    while (atual != NULL) {
        printf("Matrícula: %d, Nome: %s, Semestre: %d, Conhecimento: %s\n",
               atual->matricula, atual->nome, atual->semestre, atual->conhecimento);
        atual = atual->proximo;
    }
}

int main() {
    Candidato* candidatosAlta = NULL;
    Candidato* candidatosMedia = NULL;
    Candidato* candidatosBaixa = NULL;

    int matricula = 1, semestre;
    char nome[50], conhecimento[10];

    printf("Informe os dados dos candidatos para bolsa de pesquisa (matrícula = 0 para encerrar):\n");

    while (matricula != 0) {
        printf("Matrícula: ");
        scanf("%d", &matricula);

        if (matricula != 0) {
          printf("Nome: ");
          scanf("%s", nome);
          printf("Semestre: ");
          scanf("%d", &semestre);
          printf("Conhecimento (alta, media ou baixa): ");
          scanf("%s", conhecimento);

          if (strcmp(conhecimento, "alta") == 0) {
              candidatosAlta = inserirCandidato(candidatosAlta, matricula, nome, semestre, conhecimento);
          } else if (strcmp(conhecimento, "media") == 0) {
              candidatosMedia = inserirCandidato(candidatosMedia, matricula, nome, semestre, conhecimento);
          } else if (strcmp(conhecimento, "baixa") == 0) {
              candidatosBaixa = inserirCandidato(candidatosBaixa, matricula, nome, semestre, conhecimento);
          } else {
              printf("Conhecimento inválido. Use 'alta', 'media' ou 'baixa'.\n");
          }
        }
    }

    printf("Candidatos com conhecimento 'alta' em programação em C:\n");
    exibirCandidatos(candidatosAlta);

    printf("\nCandidatos com conhecimento 'media' em programação em C:\n");
    exibirCandidatos(candidatosMedia);

    printf("\nCandidatos com conhecimento 'baixa' em programação em C:\n");
    exibirCandidatos(candidatosBaixa);

    // Libera a memória alocada para os candidatos
    Candidato* atual = candidatosAlta;
    while (atual != NULL) {
        Candidato* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    atual = candidatosMedia;
    while (atual != NULL) {
        Candidato* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    atual = candidatosBaixa;
    while (atual != NULL) {
        Candidato* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
