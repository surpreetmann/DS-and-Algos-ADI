/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    
    if( inorder[i] == value)
        return i;
}
}

TreeNode * createTree( vector<int> &inorder, vector<int> &postorder, int low, int high, int *lastpost ){

if( low > high )
    return NULL;

TreeNode *node = new TreeNode( postorder[*lastpost] );
--(*lastpost);

if( low == high )
    return node;

int index = search( inorder, low, high, node->val );

node->right = createTree( inorder, postorder, index+1, high, lastpost );
node->left = createTree( inorder, postorder, low, index-1, lastpost );

return node;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

int postor = B.size()-1;
int inor = A.size()-1;

TreeNode *root = createTree( A, B, 0, inor, &postor );

return root;
}
