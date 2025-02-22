class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> set;

    Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> map;

    void addNodeAfter(Node* curr) {
        Node* newNode = new Node(curr->freq + 1);
        newNode->next = curr->next;
        newNode->prev = curr;
        
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    void addNodeBefore(Node* curr) {
        Node* newNode = new Node(curr->freq - 1);
        newNode->next = curr;
        newNode->prev = curr->prev;

        curr->prev->next = newNode;
        curr->prev = newNode;
    }

    void deleteNode(Node* curr) {
        if (curr->freq == 0) return;  
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(1e9);
        head->next = tail;
        tail->prev = head;
    }

    ~AllOne() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void inc(string key) {
        Node* currNode;
        int currFreq;

        if (map.find(key) != map.end()) {
            currFreq = map[key]->freq;
            currNode = map[key];
            currNode->set.erase(key);
        } else {
            currNode = head;
            currFreq = 0;
        }

        if (currNode->next->freq != currFreq + 1) {
            addNodeAfter(currNode);
        }

        Node* nextFreqNode = currNode->next;
        nextFreqNode->set.insert(key);
        map[key] = nextFreqNode;

        if (currNode != head && currNode->set.empty()) {
            deleteNode(currNode);
        }
    }

    void dec(string key) {
        if (map.find(key) == map.end()) return; 

        Node* currNode = map[key];
        currNode->set.erase(key);
        int currFreq = currNode->freq;

        if (currFreq > 1) {
            if (currNode->prev->freq != currFreq - 1) {
                addNodeBefore(currNode);
            }
            Node* prevFreqNode = currNode->prev;
            prevFreqNode->set.insert(key);
            map[key] = prevFreqNode;
        } else {
            map.erase(key);  
        }

        if (currNode->set.empty()) {
            deleteNode(currNode);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->set.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->set.begin());
    }
};
