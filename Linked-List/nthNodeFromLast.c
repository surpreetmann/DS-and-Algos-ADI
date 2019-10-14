/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list.
Given a pointer to the head node of a linked list, find the Nth node from end of the list.
findNLast(head, n): Return the Nth node from end of the list. If N is greater than size of the list, return the last node of list (return -1 if list is empty).
*/


int findNLast(struct Node* head, int n)
{
  if(head==NULL)
    return -1;
  struct Node* curr=head;
  int count=0,no=0;
  while(curr->next!=NULL)
  {
    curr=curr->next;
    count++;
  }
  if(n>count || n==1)
    return curr->data;
  else
  {
    no=count-n+1;
  }
  count=0;
  curr=head;
  while(count!=no)
  {
    curr=curr->next;
    count++;
  }
  return curr->data;
}



