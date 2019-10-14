/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list. 

Given a pointer to the head node of a linked list, find the middle node of the list.

findMiddle(head) : Return the middle node if number of nodes in linked list in odd, otherwise there will be two middle nodes and return the second middle node (return -1 if list is empty).

*/

int findMiddle(struct Node* head) 
{
  if(head==NULL)
  {
    return -1;
  }
 
  struct Node *c1=head, *c2=head;
  while(1)
  {
    if(c1==NULL)
      return c2->data;
    else if(c1->next==NULL)
      return c2->data;
    else
    {
      c2=c2->next;
      c1=c1->next->next;
    }
  }
}
