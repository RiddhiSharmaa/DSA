class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this -> key = key;
            this -> val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*>mpp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head -> next = tail;
        tail -> prev = head;
    }

    void removeNode(int key){
        Node* node = mpp[key];
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        node -> next = nullptr;
        node -> prev = nullptr;
    }
    
    void insertNode(int key){
        Node* node = mpp[key];
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        removeNode(key);
        insertNode(key);
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()){
            mpp[key] -> val = value;
            removeNode(key);
            insertNode(key);
            return;
        }
        if (mpp.size() == n){
            Node* toDel = tail -> prev;
            removeNode(toDel -> key);
            mpp.erase(toDel -> key);
        }
        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        insertNode(key);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */