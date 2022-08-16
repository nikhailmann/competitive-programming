/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution { //iterative
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}

/* //much faster recursive solution than below
class Solution {
    public ListNode reverseList(ListNode head) {
        return reverseListAux(head, null);
    }
    
    public ListNode reverseListAux(ListNode head, ListNode prev) {
        if (head == null) return prev;
        ListNode next = head.next;
        head.next = prev; 
        prev = head;
        head = next;
        return reverseListAux(head, prev);
    }
}
*/

/* very slow recursive solution
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode prev = head;
        ListNode curr = head.next;
        while (curr.next != null) {
            prev = curr;
            curr = curr.next;
        }
        curr.next = head;
        prev.next = null;
        head = curr;
        head.next = reverseList(head.next);
        return head;
    }
}
*/
