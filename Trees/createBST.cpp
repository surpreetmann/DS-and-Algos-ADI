/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* createBST(vector<int> &A,int st,int end)
{
if(st==end)
    return NULL;
int mid=(st+end)/2;
TreeNode *temp=(TreeNode*)malloc(sizeof(TreeNode));
temp->val=A[mid];
temp->left=createBST(A,st,mid);
temp->right=createBST(A,mid+1,end);

return temp;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
int n=A.size();
vector<int> v=A;
return(createBST(v,0,n));
}
