/*
Height of a tree is defined as the length of the longest downward path from root node to any leaf. If tree is empty, height is considered as -1 and for tree with only one node height is considered as 0.

Your task is that given a binary tree, find out the maximum depth of tree (also called height of tree).

Complete the function treeHeight() which takes the address of the root node of tree as parameter and return the height of the tree.
*/

/* struct Node {
  int data;
  struct Node *left, *right;
};
The above structure is used for tree node. */

int treeHeight(struct Node* t1)
{
	if(t1==NULL)
      return -1;
  else
  {
    int x=treeHeight(t1->left);
    int y=treeHeight(t1->right);
    if(x>y)
      return x+1;
    else
      return y+1;
  }
}
