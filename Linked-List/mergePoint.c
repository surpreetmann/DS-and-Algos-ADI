/*
As a linked list contains nodes, a node can belong to multiple lists. So any number of nodes can share the address of a node.

So, given two linked lists, find out if they share some nodes in tail part or not. In other words, find out whether two linked lists share some nodes in the end parts.

Complete the function findMergePoint() which takes the head node of two linked lists as parameters and return the merging node (if exists, otherwise return NULL).

*/

struct Node* findMergePoint(struct Node *head1,struct Node *head2)
{
  struct Node *first=head1,*second=head2,*temp;
  int l1=0,l2=0;
  while(first!=NULL)
  {
    l1++;
    first=first->next;
  }
  while(second!=NULL)
  {
    l2++;
    second=second->next;
  }
  l1=l1-l2;
  first=head1;
  while(l1--)
  {
    first=first->next;
  }
  second=head2;
  while(first!=NULL)
  {
    if(first==second)
      return first;
    first=first->next;
    second=second->next;
  }
  return NULL;
}