#include <stdio.h>
#include <stdlib.h>

struct no
{
    char info;
    struct no *esquerda;
    struct no *direita;
};

struct no *raiz; /* o primeiro n� da �rvore */

struct no *insere(struct no *raiz, struct no *r, char info)
{
    if (r == NULL)
    {
        /* aloca espa�o para o novo n� */
        r = (struct no *)malloc(sizeof(struct no));
        /* Verifica se alocou */
        if (r == NULL)
        {
            printf("sem mem�ria\n");
            exit(0);
        }
        /* Um novo n� n�o tem filhos */
        r->esquerda = NULL;
        r->direita = NULL;
        r->info = info;
        if (raiz == NULL)
        {
            /* primeira entrada */
            return r;
        }
        /* coloca o n� abaixo da raiz esquerda ou direita de acordo com o conte�do */
        if (info < raiz->info)
        {
            raiz->esquerda = r;
        }
        else
        {
            raiz->direita = r;
        }
        return r;
    }
    /* se chama recursivamente at� encontrar a posi��o adequada para o novo elemento */
    if (info < r->info)
        insere(r, r->esquerda, info);
    else
        insere(r, r->direita, info);
}

/* Percorre a arvore de forma ordenada */
void inorder(struct no *raiz)
{
    if (raiz == NULL)
    {
        /* se encontrar um n� terminal retorna */
        return;
    }
    inorder(raiz->esquerda);
    printf("%c ", raiz->info);
    inorder(raiz->direita);
}

/* Percorre a lista de forma pr�-ordenada */
void preorder(struct no *raiz)
{
    if (raiz == NULL)
    {
        /* se encontrar um n� terminal retorna */
        return;
    }
    printf("%c ", raiz->info);
    preorder(raiz->esquerda);
    preorder(raiz->direita);
}

/* Percorre a lista de forma p�s-ordenada */
void postorder(struct no *raiz)
{
    if (raiz == NULL)
    {
        /* se encontrar um n� terminal retorna */
        return;
    }
    postorder(raiz->esquerda);
    postorder(raiz->direita);
    printf("%c ", raiz->info);
}

/* Encontra um n� na �rvore */
struct no *search_no(struct no *raiz, char valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    while (raiz->info != valor)
    {
        if (valor < raiz->info)
        {
            raiz->esquerda;
        }
        else
        {
            raiz->direita;
        }
        if (raiz == NULL)
        {
            break;
        }
    }
    return raiz;
}

main(void)
{
    char s[80];
    struct no *result;
    /* inicializa a raiz */
    raiz = NULL;
    do
    {
        printf("insira uma letra ou ENTER para sair: ");
        /* funcao que le string do C */
        gets(s);
        if (raiz == NULL)
            raiz = insere(raiz, raiz, *s);
        else
            insere(raiz, raiz, *s);
    } while (*s);

    printf("\n\nOrdenada\n");
    inorder(raiz);

    printf("\n\nPre-ordenada\n");
    preorder(raiz);

    printf("\n\nPos-ordenada\n");
    postorder(raiz);

    result = search_no(raiz, 'a');
    if (result != NULL)
    {
        printf("\n\nEncontrado: %c\n", result->info);
    }
    else
    {
        printf("\n\nLetra 'a' nao encontrada.\n");
    }
}
