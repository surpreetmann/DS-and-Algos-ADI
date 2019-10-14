/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list.
Given the head node */

struct Node*  reverseList(struct Node* head) 
{
  if(head==NULL || head->next==NULL)
    return head;
  struct Node *curr=head, *prev=NULL, *next=curr->next;
 while(next!=NULL)
 {
   curr->next=prev;
   prev=curr;
   curr=next;
   next=next->next;
 }
  curr->next=prev;
    head=curr;
return head;
}