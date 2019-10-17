/*
Given a binary tree, print it in inorder, preorder and postorder fashion with recursion.
*/

/* struct Node
{
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node.
*/

void inorder(struct Node* root)
{
if(root==NULL)
  return;
  else
  {
    inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
  }
}
void preorder(struct Node* root)
{
if(root==NULL)
  return;
   else
   {
     printf("%d ",root->data);
  preorder(root->left);
   preorder(root->right);
}
}
void postorder(struct Node* root)
{
if(root==NULL)
  return;
 else
 {
   postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}
}
