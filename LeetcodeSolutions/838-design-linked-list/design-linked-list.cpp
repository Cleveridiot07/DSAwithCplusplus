class MyLinkedList {
    ListNode* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        ListNode* temp = head;
        while(index>0 && temp!= nullptr){
            temp = temp->next;
            index--;
        }
        if(temp!=nullptr) return temp->val;
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* node =new ListNode();
        node->val = val;
        node->next = nullptr;
        if(head == nullptr){
            head = node;
        }else{
            ListNode* temp = head;
            head = node;
            node->next = temp;
        }
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode();
        node->val = val;
        node->next = nullptr;
        if(head == nullptr){
            head = node;
        }else{
            ListNode* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        ListNode* node =new ListNode();
        node->val = val;
        node->next = nullptr;
        // head is null
        if(head == nullptr){
            if(index != 0) return;
            head = node;
            return; 
        }


        ListNode* temp = head;
        // inserting at head when head is not null
        if(index == 0){
            head = node;
            node -> next = temp;
            return;
        }

        while(index>1 && temp!= nullptr){
            temp = temp->next;
            index--;
        }

        if(temp == nullptr) return addAtTail(val);
        ListNode* next = temp->next;
        temp->next = node;
        node->next = next;
        return;
    }
    
    void deleteAtIndex(int index) {
        if (!head) return; 

        ListNode* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) return;
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */