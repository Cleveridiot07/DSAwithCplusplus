class Node{
    int key, val;
    Node next;
    Node prev;
    Node(int key, int value){
        this.key = key;
        this.val = value;
        this.next = null;
        this.prev = null;
    }
}
 
class LRUCache {
    Node head, tail;
    HashMap<Integer, Node>hm;
    int capacity;
    public LRUCache(int capacity) {
        hm = new HashMap<>();
        head = null;
        tail = null;
        this.capacity = capacity;
    }
 
    public void addAtHead(Node curr){
        if(head==null){
            head = curr;
            tail = curr;
            return ;
        }
        curr.next = head;
        head.prev = curr;
        head = curr;
    }
 
    public Node deleteAtTail(){
        if(tail==null){
            return null;
        }
        if(tail.prev==null){
            Node ans = tail;
            tail = null;
            head = null;
            return ans;
        }
        Node prev = tail.prev;
        prev.next = null;
        tail.prev = null;
        Node ans = tail;
        tail = prev;
        return ans;
    }
    Node deleteHead(){
        Node curr = head;
        head = head.next;
        if(head!=null){
            head.prev = null;
        }
        else{
            head = null;
            tail = null;
        }
        return curr;
    }
    void deleteNode(Node curr){
        if(curr.prev==null){
            // if the node to be deleted is at head
            deleteHead();
            return ;
        }
        if(curr.next==null){
            deleteAtTail();
            return ;
        }
        Node prev = curr.prev;
        prev.next = prev.next.next;
        prev.next.prev = prev;
 
        curr.next = null;
        curr.prev = null;
    }
 
    public int get(int key) {
        if(!hm.containsKey(key)){
            return -1;
        }
        Node curr = hm.get(key);
        deleteNode(curr);
        addAtHead(curr);
        return curr.val;
    }
 
    public void put(int key, int value) {
        Node curr;
        if(hm.containsKey(key)){
            curr = hm.get(key);
            deleteNode(curr);
            curr.val = value;
        }
        else{
            curr = new Node(key, value);
        }
        hm.put(key, curr);
        addAtHead(curr);
        if(hm.size() > capacity){
            Node toBeDel = deleteAtTail();
            hm.remove(toBeDel.key);
        }
    }
}
 
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */