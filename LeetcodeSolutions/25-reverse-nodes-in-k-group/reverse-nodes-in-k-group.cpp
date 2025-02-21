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
    ListNode* mergeList(ListNode* head1,ListNode* head2) {
        if(head1 == nullptr) return head2;
        ListNode* temp = head1;
        while (temp->next != nullptr) {
            temp = temp->next;              
        }
        temp->next = head2;
        return head1; 
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        
        int t = k;
        
        while(t>1 && temp!= nullptr){
            temp = temp -> next;
            t--;
        }
        
        if(temp == nullptr) return head;
        
        ListNode* nextList = nullptr;
        
        if(temp!=nullptr) nextList = temp->next;
        if(temp!=nullptr) temp->next = nullptr;
        
        ListNode* rev = reverseList(head);
        head->next = reverseKGroup(nextList,k);
        return rev;
    }
};