/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root.left != null && root.right != null) {
            if (p.val <= root.val && q.val >= root.val || q.val <= root.val && p.val >= root.val) {
                return root;
            } else if (p.val < root.val && q.val < root.val) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return root;
    }
}
