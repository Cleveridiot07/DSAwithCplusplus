class Solution {
public:
    ListNode* reverseHead(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* helper(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* temp = head;
        int count = 0;


        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        bool shouldReverse = (count % 2 == 0);

        temp = head;
        for (int i = 1; i < count; i++) {
            temp = temp->next;
        }

        ListNode* rem = temp->next; 
        temp->next = nullptr; 

        if (shouldReverse) {
            ListNode* reversed = reverseHead(head);
            head->next = helper(rem, k + 1);
            return reversed;
        } else {
            temp->next = helper(rem, k + 1);
            return head;
        }
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return helper(head, 1);
    }
};
