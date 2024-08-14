/**
  2)  Construa um programa em C que cumpra os seguintes requisitos:
    O programa principal deve apresentar um menu com as seguintes opções (nova leitura, consultar e sair);
    Opção novo = solicite ao usuário que informe dados de leitura de um data logger contendo as seguintes informações: código do equipamento, temperatura, velocidade do vento, umidade relativa do ar e salve os dados (4 informações) em um único nó de uma lista duplamente encadeada;
    Opção consultar =  solicite ao usuário que informe o código do equipamento e apresente na tela os dados de todas as leituras salvas na lista para o código de equipamento informado, sendo que a consulta deve iniciar o último para o primeiro elemento da lista;
    Opção sair = encerra o programa;
*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do componente
struct Componente
{
    int codigo;
    int numeroSerie;
    struct Componente *proximo;
    struct Componente *anterior;
};

// Estrutura para armazenar a lista e referências para o primeiro e último nós
struct ListaComponentes
{
    struct Componente *primeiro;
    struct Componente *ultimo;
};

// Função para inicializar a lista de componentes
void inicializarLista(struct ListaComponentes *lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

// Função para adicionar um componente à lista duplamente encadeada
void adicionarComponente(struct ListaComponentes *lista, int codigo, int numeroSerie)
{
    struct Componente *novoComponente = (struct Componente *)malloc(sizeof(struct Componente));
    novoComponente->codigo = codigo;
    novoComponente->numeroSerie = numeroSerie;
    novoComponente->proximo = NULL;

    if (lista->primeiro == NULL)
    {
        novoComponente->anterior = NULL;
        lista->primeiro = novoComponente;
    }
    else
    {
        novoComponente->anterior = lista->ultimo;
        lista->ultimo->proximo = novoComponente;
    }

    lista->ultimo = novoComponente;
}

// Função para imprimir os componentes da lista do primeiro para o último
void imprimirListaDoInicioAoFim(struct ListaComponentes lista)
{
    printf("Componentes do primeiro para o último:\n");
    struct Componente *atual = lista.primeiro;
    while (atual != NULL)
    {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para imprimir os componentes da lista do último para o primeiro
void imprimirListaDoFimAoInicio(struct ListaComponentes lista)
{
    if (lista.ultimo == NULL)
    {
        return;
    }

    printf("Componentes do último para o primeiro:\n");
    struct Componente *atual = lista.ultimo;
    while (atual != NULL)
    {
        printf("Código: %d, Número de Série: %d\n", atual->codigo, atual->numeroSerie);
        atual = atual->anterior;
    }
    printf("\n");
}

// Função para consultar um componente pelo número de série
void consultarComponente(struct ListaComponentes lista, int numeroSerie)
{
    struct Componente *atual = lista.primeiro;
    int posicao = 0;
    while (atual != NULL)
    {
        if (atual->numeroSerie == numeroSerie)
        {
            printf("O dispositivo com número de série %d está na posição %d na lista.\n", numeroSerie, posicao);
            return;
        }
        atual = atual->proximo;
        posicao++;
    }
    printf("Dispositivo com número de série %d não encontrado na lista.\n", numeroSerie);
}

// Função para editar um componente pelo número de série
void editarComponente(struct ListaComponentes *lista, int numeroSerie, int novoNumeroSerie)
{
    struct Componente *atual = lista->primeiro;
    while (atual != NULL)
    {
        if (atual->numeroSerie == numeroSerie)
        {
            atual->numeroSerie = novoNumeroSerie;
            printf("Número de série do dispositivo atualizado com sucesso.\n");
            return;
        }
        atual = atual->proximo;
    }
    printf("Dispositivo com número de série %d não encontrado na lista. Não foi possível editar.\n", numeroSerie);
}

// Função para apagar um componente pelo número de série
void apagarComponente(struct ListaComponentes *lista, int numeroSerie)
{
    struct Componente *atual = lista->primeiro;
    while (atual != NULL)
    {
        if (atual->numeroSerie == numeroSerie)
        {
            if (atual->anterior != NULL)
            {
                atual->anterior->proximo = atual->proximo;
            }
            else
            {
                lista->primeiro = atual->proximo;
            }

            if (atual->proximo != NULL)
            {
                atual->proximo->anterior = atual->anterior;
            }
            else
            {
                lista->ultimo = atual->anterior;
            }

            free(atual);
            printf("Dispositivo com número de série %d removido com sucesso.\n", numeroSerie);
            return;
        }
        atual = atual->proximo;
    }
    printf("Dispositivo com número de série %d não encontrado na lista. Não foi possível remover.\n", numeroSerie);
}

int main()
{
    struct ListaComponentes lista;
    inicializarLista(&lista);
    int codigo, numeroSerie, opcao, numeroSerieConsulta, novoNumeroSerie;

    do
    {
        printf("Menu:\n");
        printf("1. Inserir dispositivo\n");
        printf("2. Consultar dispositivo\n");
        printf("3. Editar dispositivo\n");
        printf("4. Apagar dispositivo\n");
        printf("5. Imprimir lista do início ao fim\n");
        printf("6. Imprimir lista do fim ao início\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o código e número de série do componente (ou digite 0 para encerrar):\n");
            do
            {
                printf("Código: ");
                scanf("%d", &codigo);

                if (codigo != 0)
                {
                    printf("Número de Série: ");
                    scanf("%d", &numeroSerie);

                    adicionarComponente(&lista, codigo, numeroSerie);
                }
            } while (codigo != 0);
            break;
        case 2:
            printf("Digite o número de série a ser consultado: ");
            scanf("%d", &numeroSerieConsulta);
            consultarComponente(lista, numeroSerieConsulta);
            break;
        case 3:
            printf("Digite o número de série do dispositivo a ser editado: ");
            scanf("%d", &numeroSerie);
            printf("Digite o novo número de série: ");
            scanf("%d", &novoNumeroSerie);
            editarComponente(&lista, numeroSerie, novoNumeroSerie);
            break;
        case 4:
            printf("Digite o número de série do dispositivo a ser apagado: ");
            scanf("%d", &numeroSerie);
            apagarComponente(&lista, numeroSerie);
            break;
        case 5:
            imprimirListaDoInicioAoFim(lista);
            break;
        case 6:
            imprimirListaDoFimAoInicio(lista);
            break;
        case 0:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);

    // Liberar a memória alocada para os componentes
    struct Componente *atual = lista.primeiro;
    while (atual != NULL)
    {
        struct Componente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
