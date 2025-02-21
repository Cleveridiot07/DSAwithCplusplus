class Solution {
public:
    struct Compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for (ListNode* curr : lists) {
            if (curr != nullptr) pq.push(curr);
        }

        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            
            if (head == nullptr) {
                head = curr;
                temp = head;
            } else {
                temp->next = curr;
                temp = temp->next;
            }

            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return head;
    }
};