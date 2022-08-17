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
    
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int[] longestPath = {0};
        diameterAux(root, longestPath);
        return longestPath[0];
    }
    
    private int diameterAux(TreeNode node, int[] longestPath) {
        if (node == null) {
            return 0;
        }
        int left = diameterAux(node.left, longestPath);
        int right = diameterAux(node.right, longestPath);
        longestPath[0] = Math.max(longestPath[0], left + right);
        return Math.max(left, right) + 1;
    }
}

/* slow solution
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int l = root.left != null ? 1 + Aux(root.left) : 0;
        int r = root.right != null ? 1 + Aux(root.right) : 0;
        return Math.max(l+r, Math.max(diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right)));
        
    }
    
    public int Aux(TreeNode root) {
        if (root == null) return -1; //return -1 not 0!
        return 1 + Math.max(Aux(root.left), Aux(root.right));
    }
}
*/
