/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution { //Bottom up solution!
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        return isBalancedAux(root) != -2;
    }
    
    public Integer isBalancedAux(TreeNode root) {
        if (root == null) {
            return -1;
        }
        int l = isBalancedAux(root.left);
        int r = isBalancedAux(root.right);
        if (l == -2 || r == -2 || Math.abs(l-r) > 1) {
            return -2;
        }
        return 1 + Math.max(l, r);
        
    }
}

/** //top down solution is slower
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        int l = isBalancedAux(root.left);
        int r = isBalancedAux(root.right);
        return Math.abs(l-r) <= 1 && isBalanced(root.left) && isBalanced(root.right); //check every subtree!
    }
    
    public Integer isBalancedAux(TreeNode root) {
        if (root == null) {
            return -1; //-1 not 0
        } else {
            return 1 + Math.max(isBalancedAux(root.left), isBalancedAux(root.right));
        }
    }
}
**/
