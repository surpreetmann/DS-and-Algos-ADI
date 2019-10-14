/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list.
Given a linked-list as input, check whether it contains a loop or not. If there is a loop return the number of nodes in the loop, otherwise return 0.

Complete the function loopInList() which takes the head node of a linked list as a parameter and return the number of nodes in loop if exists, 0 otherwise.
*/

int  loopInList(struct Node* head) 
{
  if(head==NULL)
    return 0;
  struct Node *slow=head, *fast=head->next->next;
  while(slow!=fast && fast)
  {
    if(slow==fast)
      break;
    slow=slow->next;
    fast=fast->next;
    if(fast==NULL)
      break;
    fast=fast->next;
  }
  if(fast==NULL)
    return 0;
  slow=slow->next;
  int count=1;
  while(slow!=fast)
  {
    count++;
    slow=slow->next;
  }
  return count;
}