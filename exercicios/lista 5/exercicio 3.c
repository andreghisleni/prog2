/**
  3) Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe dados de alunos para seleção de uma vaga para bolsa de pesquisa, contendo as seguintes informações: matricula e conhecimento na área de programação em C (1 - iniciante ou 2 - avançado);
    As informações devem ser armazenadas em uma única estrutura chamada candidato e enviada como parâmetro para um função de armazenamento;
    O sistema só deve parar de solicitar as informações de candidatos quando o usuário informar o código da matrícula = 0;
    A função de armazenamento deve retornar um estrutura com 2 vetores e seus respectivos tamanhos, onde cada vetor armazena os candidatos separados por conhecimento na área de programação;
    Para otimização da memória, os vetores devem ser incrementados de 3 em três posições a medida que apenas com uma posição disponível;
    O programa principal deve mostrar os candidatos separados por conhecimento em programação antes de encerrar;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de candidato
struct Candidato {
    int matricula;
    int conhecimento; // 1 - iniciante, 2 - avançado
};

// Função para armazenar os candidatos em vetores separados por conhecimento
void armazenarCandidatos(struct Candidato **iniciante, int *tamIniciante, struct Candidato **avancado, int *tamAvancado, struct Candidato candidato) {
    if (candidato.conhecimento == 1) {
        if (*tamIniciante % 3 == 0) {
            *iniciante = realloc(*iniciante, (*tamIniciante + 3) * sizeof(struct Candidato));
        }
        (*iniciante)[*tamIniciante] = candidato;
        (*tamIniciante)++;
    } else if (candidato.conhecimento == 2) {
        if (*tamAvancado % 3 == 0) {
            *avancado = realloc(*avancado, (*tamAvancado + 3) * sizeof(struct Candidato));
        }
        (*avancado)[*tamAvancado] = candidato;
        (*tamAvancado)++;
    }
}

int main() {
    int matricula;
    int conhecimento;
    int tamIniciante = 0;
    int tamAvancado = 0;
    struct Candidato *candidatosIniciante = NULL;
    struct Candidato *candidatosAvancado = NULL;

    printf("Digite os dados dos candidatos (matricula e conhecimento em C)\n");
    printf("Use 0 como matricula para encerrar:\n");

    while (matricula != 0) {
        printf("Matricula (0 para encerrar): ");
        scanf("%d", &matricula);

        if(matricula != 0) {
            printf("Conhecimento (1 - iniciante, 2 - avançado): ");
            scanf("%d", &conhecimento);

            struct Candidato candidato;
            candidato.matricula = matricula;
            candidato.conhecimento = conhecimento;

            armazenarCandidatos(&candidatosIniciante, &tamIniciante, &candidatosAvancado, &tamAvancado, candidato);
        }
    };

    printf("\nCandidatos Iniciantes:\n");
    for (int i = 0; i < tamIniciante; i++) {
        printf("Matricula: %d\n", candidatosIniciante[i].matricula);
    }

    printf("\nCandidatos Avançados:\n");
    for (int i = 0; i < tamAvancado; i++) {
        printf("Matricula: %d\n", candidatosAvancado[i].matricula);
    }

    free(candidatosIniciante);
    free(candidatosAvancado);

    return 0;
}
