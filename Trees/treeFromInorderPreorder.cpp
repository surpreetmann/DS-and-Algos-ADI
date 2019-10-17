/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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
int search( vector<int> &inorder, int l, int j, int value){

for( int i=l; i<=j; i++ ){
    
    if( value == inorder[i] )
        return i;
}

//return -1;
}

TreeNode* createTree( vector<int> &inorder, vector<int> &preorder, int low, int high, int *lastpos ){

if( low > high )
    return NULL;
    
TreeNode *node = new TreeNode( preorder[*lastpos] );
++(*lastpos);

int index = search( inorder, low, high, node->val );

node->left = createTree( inorder, preorder, low, index-1, lastpos );
node->right = createTree( inorder, preorder, index+1, high, lastpos );

return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

if( A.empty() || B.empty() )
    return NULL;

int inor = A.size()-1;
int postor = 0;

return createTree( B, A, 0, inor, &postor );
}
