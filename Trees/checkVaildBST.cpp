/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
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

int isValidBST(TreeNode* root, int minValue, int maxValue)
{
    if (!root)  
        return 1;
    if (root->val > minValue && root->val < maxValue && isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue))
        return 1;
    else
        return 0;
}
int Solution::isValidBST(TreeNode* A) {
    return isValidBST(A, INT_MIN, INT_MAX);
}