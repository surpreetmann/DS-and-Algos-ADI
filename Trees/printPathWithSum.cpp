/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void add(TreeNode * A, int B, vector < vector < int >> & sol, vector < int > & vec, int sum)
{
    if (A == NULL)
    return;
    sum = sum + A->val;
    vec.push_back(A->val);
    if (sum == B && (A->right == NULL && A->left==NULL)){
        sol.push_back(vec);
    }
    add(A->left, B, sol, vec, sum);
    add(A->right, B, sol, vec, sum);
    vec.pop_back();
}

vector < vector < int > > Solution::pathSum(TreeNode * A, int B) {
    vector < vector < int > > sol;
    vector < int > vec;
    add(A, B, sol, vec, 0);
    return sol;
}