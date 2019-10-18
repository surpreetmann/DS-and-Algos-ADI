#include <stdio.h>

typedef struct Tree
{
  int data;
  struct Tree *left;
  struct Tree *right;
} Tree;

Tree *newNode(int data)
{
  Tree *node = (Tree *)malloc(sizeof(Tree));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

void deleteTree(Tree* node)  
{ 
    if (node == NULL) 
      return; 
    deleteTree(node->left); 
    deleteTree(node->right); 
    
    printf("\n Deleting node: %d", node->data); 
    free(node); 
}  

int main()
{
  Tree *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  deleteTree(root);
  root=NULL;
  printf("Tree Deleted");

  return 0;
}