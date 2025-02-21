
class Solution {
    ListNode* mergeList(ListNode* head1,ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode dummy(0);
        ListNode* pre = &dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                pre->next = temp1;
                temp1=temp1->next;
            }else{
                pre->next = temp2;
                temp2=temp2->next;
            }
            pre=pre->next;
        }
        if(temp1) pre->next = temp1;
        if(temp2) pre->next = temp2;
        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != nullptr) prev->next = nullptr;

        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(slow);
        return mergeList(l1,l2);

    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};