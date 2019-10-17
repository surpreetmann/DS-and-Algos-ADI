/*Merge k sorted linked lists and return it as one sorted list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class myCompare
{
public:
bool operator()(ListNode* a, ListNode* b)
{
return a->val > b->val;
}
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

priority_queue<ListNode*,vector<ListNode*>, myCompare> q;

for(int i=0;i<A.size();i++)
q.push(A[i]);

ListNode* head = NULL;
// q.pop();

ListNode* prev = NULL;

while(!q.empty())
{
    ListNode* temp1 = q.top();
    q.pop();
    if(!prev)
        head = temp1;
    else
        prev->next = temp1;
    prev = temp1;
    
    if(temp1 -> next != NULL)
        q.push(temp1 -> next);
}
prev->next = NULL;
return head;
}
