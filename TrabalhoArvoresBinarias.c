#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int value)
{
  if (root == NULL)
  {
    return createNode(value);
  }

  if (value < root->data)
  {
    root->left = insert(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = insert(root->right, value);
  }

  return root;
}

Node *minValueNode(Node *node)
{
  Node *current = node;

  while (current && current->left != NULL)
  {
    current = current->left;
  }

  return current;
}

Node *deleteNode(Node *root, int value)
{
  if (root == NULL)
  {
    return root;
  }

  if (value < root->data)
  {
    root->left = deleteNode(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = deleteNode(root->right, value);
  }
  else
  {
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

Node *search(Node *root, int value)
{
  if (root == NULL || root->data == value)
  {
    return root;
  }

  if (value < root->data)
  {
    return search(root->left, value);
  }

  return search(root->right, value);
}

void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

int main()
{
  Node *root = NULL;
  int choice, value;

  do
  {
    printf("\nMenu:\n");
    printf("1. Incluir elemento na árvore\n");
    printf("2. Remover elemento da árvore\n");
    printf("3. Consultar elemento na árvore\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);
    system("clear");

    switch (choice)
    {
    case 1:
      printf("Digite o valor a incluir: ");
      scanf("%d", &value);
      root = insert(root, value);
      printf("Elemento %d incluído na árvore.\n", value);
      break;
    case 2:
      printf("Digite o valor a remover: ");
      scanf("%d", &value);
      root = deleteNode(root, value);
      printf("Elemento %d removido da árvore.\n", value);
      break;
    case 3:
      printf("Digite o valor a buscar: ");
      scanf("%d", &value);
      if (search(root, value) != NULL)
      {
        printf("Elemento %d encontrado na árvore.\n", value);
      }
      else
      {
        printf("Elemento %d não encontrado na árvore.\n", value);
      }
      break;
    case 4:
      printf("Encerrando o programa.\n");
      break;

    default:
      printf("Opção inválida. Escolha novamente.\n");
    }
  } while (choice != 4);

  return 0;
}
