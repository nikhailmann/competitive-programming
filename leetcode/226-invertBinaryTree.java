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
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return root;
        TreeNode ans = invertTreeAux(root);
        return ans;
    }
    
    public TreeNode invertTreeAux(TreeNode root) {
        if (root.left == null && root.right == null) {
            return root;
        } else if (root.left != null && root.right == null) {
            root.right = invertTreeAux(root.left);
            root.left = null;
            return root;
        } else if (root.left == null && root.right != null) {
            root.left = invertTreeAux(root.right);
            root.right = null;
            return root;
        } else {
            TreeNode holder = root.left;
            root.left = invertTreeAux(root.right);
            root.right = invertTreeAux(holder);
            return root;
        }
    }
}
