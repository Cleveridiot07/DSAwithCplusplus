class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode P1 = head;
        ListNode P2 = head;

        while (P2 != null && P2.next != null) {
            P1 = P1.next;
            P2 = P2.next.next;

            if (P1 == P2) {
                return true;
            }
        }

        return false;
    }
}
