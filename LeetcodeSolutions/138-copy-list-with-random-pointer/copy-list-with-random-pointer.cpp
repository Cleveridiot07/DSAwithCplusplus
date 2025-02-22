/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        
        Node* temp = head;
        
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }

        Node* curr1 = head;
        Node* curr2 = head->next;

        while(curr1 && curr2){
            if(curr1->random != nullptr){
                curr2->random = curr1->random->next;
            }else{
                curr2->random = nullptr;
            }
            curr1 = curr1->next->next;
            if(curr2->next != nullptr) curr2 = curr2->next->next;
        }

        curr1 = head;
        Node* copyHead = head->next;
        curr2 = copyHead;

        while (curr1) {
            curr1->next = curr1->next ? curr1->next->next : nullptr;
            curr1 = curr1->next;
            if (curr2->next) {
                curr2->next = curr2->next->next;
                curr2 = curr2->next;
            }
        }
        
        return copyHead;
    }
};