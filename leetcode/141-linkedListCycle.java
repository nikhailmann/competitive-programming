/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}

/* my original solution
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode currnode = head;
        ArrayList<ListNode> arr = new ArrayList<ListNode>();
        while (currnode != null) {
            if (arr.contains(currnode.next)) {
                return true;
            }
            arr.add(currnode.next);
            currnode = currnode.next;
        }
        return false;
    }
}
*/
