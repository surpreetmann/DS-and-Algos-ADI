/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    
    TreeNode *root=A;
    int sum=0;
    if(root)
    {
        sum+=root->val;
        if(sum==B && root->left==NULL && root->right==NULL)
            return 1;
        else if( hasPathSum(root->left,B-sum))
            return 1;
        else if( hasPathSum(root->right,B-sum))
            return 1;
    }

return 0;
}