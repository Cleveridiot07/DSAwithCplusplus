class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head){
            return head;
        }
        int length=1;
        ListNode* tail=head;
        ListNode* cur=head;
        while (tail->next){
            tail=tail->next;
            length++;
        }
        k=k%length;
        if (k==0){
            return head;
        }
        for(int i=0;i<length-k-1;i++){
            cur=cur->next;
        }
        ListNode* newh=cur->next;
        cur->next=nullptr;
        tail->next=head;
        return newh;
    }
};