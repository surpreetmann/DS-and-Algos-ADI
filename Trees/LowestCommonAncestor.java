/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.
*/
/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class LowestCommonAncestor {

    int least = -1;
    
    public boolean findN(TreeNode node, int B, int C)
    {
        
        if(least != -1)
            return false;
        if(node == null)
            return false;
        
        boolean left = findN(node.left, B, C);
        boolean right = findN(node.right, B, C);
        if(node.val == B || node.val == C)
        {
            if(B == C)
            {
                least = node.val;
                return true;
            }
            if(left || right)
            {
                least = node.val;
                return true;
            }
            return true;
        }
        if(left && right)
        {
            least = node.val;
            return true;
        }
        return left || right;
    }
    
    public int lca(TreeNode A, int B, int C) {
        
        findN(A, B, C);
        return least;
        
    }
}
    