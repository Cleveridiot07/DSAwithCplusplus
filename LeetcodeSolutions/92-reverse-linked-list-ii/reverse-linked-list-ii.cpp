class Solution {
private:
    pair<ListNode*, ListNode*> reverseList(ListNode* head) {
        if (!head || !head->next) return {head, head};

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return {prev, head};
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* tail = curr;
        for (int i = left; i < right; i++) {
            tail = tail->next;
        }
        
        ListNode* nextNode = tail->next;
        tail->next = nullptr;

        auto [newHead, newTail] = reverseList(curr);
        prev->next = newHead;
        newTail->next = nextNode;

        return dummy.next;
    }
};
