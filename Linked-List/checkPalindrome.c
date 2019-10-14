/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list.
Check if linked list is palindrome or not. Return 1 if palindrome, else 0 */

int checkfunc(struct Node** left,struct Node* right)
{
  if(right==NULL)
    return 1;
  int res=checkfunc(left,right->next) && ((*left)->data == right->data);
  (*left)= (*left)->next;
  return res;
}

int  checkPalindrome(struct Node* head) 
{
  if(head==NULL)
    return 0;
	int result=checkfunc(&head,head);
  return result;
}