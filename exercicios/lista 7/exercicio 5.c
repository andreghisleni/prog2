/**
  5)  Construa um programa em C que cumpra os seguintes requisitos:
    No programa principal, solicite ao usuário que informe dados de alunos para seleção de uma vaga para bolsa de pesquisa, contendo as seguintes informações: matricula, nome, semestre, conhecimento na área de programação em C (básico ou avançado);
    As 4 informações devem ser armazenadas em uma única estrutura chamada candidato e enviada como parâmetro para um função de armazenamento;
    A função de armazenamento deve manter e retornar um estrutura com 2 listas duplamente encadeadas distintas, onde cada lista armazena os candidatos separados por conhecimento na área de programação;
    O sistema só deve parar de solicitar as informações de candidatos quando o usuário informar o código da matrícula = 0;
    O programa principal deve mostrar os candidatos armazenados em cada lista antes de encerrar, iniciando do último elemento da lista;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para os candidatos
typedef struct Candidato {
    int matricula;
    char nome[50];
    int semestre;
    char conhecimento[15]; // "básico" ou "avançado"
    struct Candidato* proximo;
    struct Candidato* anterior;
} Candidato;

// Definição da estrutura para as listas de candidatos
typedef struct ListaCandidatos {
    Candidato* inicio;
    Candidato* fim;
} ListaCandidatos;

// Função para inicializar uma lista de candidatos
ListaCandidatos inicializarLista() {
    ListaCandidatos lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    return lista;
}

// Função para inserir um candidato na lista de candidatos
void inserirCandidato(ListaCandidatos* lista, Candidato candidato) {
    Candidato* novoCandidato = (Candidato*)malloc(sizeof(Candidato));
    if (novoCandidato == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    *novoCandidato = candidato;
    novoCandidato->proximo = NULL;
    novoCandidato->anterior = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoCandidato;
        lista->fim = novoCandidato;
    } else {
        lista->fim->proximo = novoCandidato;
        novoCandidato->anterior = lista->fim;
        lista->fim = novoCandidato;
    }
}

// Função para exibir os candidatos de uma lista em ordem reversa
void exibirCandidatosReverso(ListaCandidatos lista, const char* conhecimento) {
    Candidato* atual = lista.fim;
    printf("Candidatos com conhecimento %s (em ordem reversa):\n", conhecimento);
    while (atual != NULL) {
        if (strcmp(atual->conhecimento, conhecimento) == 0) {
            printf("Matrícula: %d, Nome: %s, Semestre: %d\n", atual->matricula, atual->nome, atual->semestre);
        }
        atual = atual->anterior;
    }
    printf("\n");
}

int main() {
    ListaCandidatos candidatosBasico = inicializarLista();
    ListaCandidatos candidatosAvancado = inicializarLista();
    int matricula = 1;
    
    while (matricula != 0) {
        Candidato candidato;

        printf("Informe a matrícula do candidato (ou digite 0 para encerrar): ");
        scanf("%d", &matricula);

        if (matricula != 0) {
    
            candidato.matricula = matricula;

            printf("Nome do candidato: ");
            scanf(" %[^\n]", candidato.nome);

            printf("Semestre do candidato: ");
            scanf("%d", &candidato.semestre);

            printf("Conhecimento em programação em C (básico ou avançado): ");
            scanf(" %[^\n]", candidato.conhecimento);

            if (strcmp(candidato.conhecimento, "básico") == 0) {
                inserirCandidato(&candidatosBasico, candidato);
            } else if (strcmp(candidato.conhecimento, "avançado") == 0) {
                inserirCandidato(&candidatosAvancado, candidato);
            } else {
                printf("Conhecimento em programação em C inválido. Tente novamente.\n");
            }
        }
        
    }

    // Exibir os candidatos em ordem reversa de acordo com o conhecimento
    exibirCandidatosReverso(candidatosBasico, "básico");
    exibirCandidatosReverso(candidatosAvancado, "avançado");

    // Liberar a memória alocada para os candidatos
    Candidato* atual = candidatosBasico.inicio;
    while (atual != NULL) {
        Candidato* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    atual = candidatosAvancado.inicio;
    while (atual != NULL) {
        Candidato* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
