/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int len(ListNode *ptr)
{
int i=0;
while(ptr)
{
i++;
ptr= ptr->next;
}

return i;
}

ListNode *reverse(ListNode *A)
{
ListNode *prev=NULL, *curr=A;

while(curr)
{
    ListNode *save = curr->next;
    curr->next = prev;
    
    prev = curr;
    curr = save;
}
return prev;
}

ListNode* Solution::reorderList(ListNode* A) {

if(A==NULL || A->next==NULL)
return A;

ListNode *left=A, *right=A, *save=NULL;

int l = len(A);
int mid = l/2 + l%2;

for(int i=1;i<=mid;i++)
{
    save = right;
    right = right->next;
}

if(save)
save->next = NULL;

right = reverse(right);

bool f=0;
while(left || right)
{
    if(!f)
    {
        save = left->next;
        left->next = right;
        
        left = save;
    }
    else
    {
        save = right->next;
        right->next = left;
        
        right = save;
    }
    f = 1-f;
}

return A;
}