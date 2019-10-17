/*
Given a binary tree, check whether it is a mirror of itself (or palindrome)(ie, symmetric around its center).
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

bool isPalindrome(TreeNode*  A, TreeNode* B)
{
    if(A==NULL || B==NULL)
    {
        return A==B;
    }
    
    return isPalindrome(A->left, B->right) && isPalindrome(A->right, B->left) && A->val==B->val;
}

int Solution::isSymmetric(TreeNode* A) {
    
    return A==NULL || isPalindrome(A->left,A->right);
}
