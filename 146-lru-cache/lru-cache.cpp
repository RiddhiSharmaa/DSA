class LRUCache {
public:
    int cnt = 0;
    int cap;
    struct Node{
        int key;
        int data;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this -> key = key;
            this -> data = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    unordered_map<int, Node*>mpp;
    Node* head;
    Node* tail;

    void update(int key){
        Node* temp = mpp[key];
        Node* prevNode = temp -> prev;
        Node* nextNode = temp -> next;
        if (head == tail){
            return;
        }
        if (temp == head){
            nextNode -> prev = nullptr;
            head = head -> next;
            tail -> next = temp;
            temp -> prev = tail;
            temp -> next = nullptr;
            tail = tail -> next;
        } else if (temp != tail){
            prevNode -> next = nextNode;
            nextNode -> prev = prevNode;
            tail -> next = temp;
            temp -> prev = tail;
            temp -> next = nullptr;
            tail = tail -> next;
        }
    }

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()){
            update(key);
            return mpp[key] -> data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()){
            update(key);
            mpp[key] -> data = value;
            return;
        } else {
            Node* newNode = new Node(key, value);
            if (cnt == 0){
                head = newNode;
                tail = newNode;
                mpp[key] = newNode;
                cnt++;
            } else if (cnt == cap){
                mpp.erase(head -> key);
                Node* temp = head;
                head = head -> next;
                if (head) {
                    head -> prev = nullptr;
                    tail -> next = newNode;
                    newNode -> prev = tail;
                    tail = tail -> next;
                } else {
                    head = newNode;
                    tail = newNode;
                }
                temp -> next = nullptr;
                delete(temp);
                mpp[key] = newNode;
            } else {
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = tail -> next;
                mpp[key] = newNode;
                cnt++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */