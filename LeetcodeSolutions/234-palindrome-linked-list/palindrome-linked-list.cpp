/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    bool compareList(ListNode* head1, ListNode* head2) {
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1 == nullptr && head2 == nullptr; 
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next; 
            curr->next = prev;           
            prev = curr;                
            curr = temp;                 
        }
        return prev; 
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; 

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* secondHalf = (fast == nullptr) ? reverseList(slow) : reverseList(slow->next);
        return compareList(head, secondHalf);
    }
};
