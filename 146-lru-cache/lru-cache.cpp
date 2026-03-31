class LRUCache {
public:
    struct Node{
        int key, val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this -> key = key;
            this -> val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int maxCapacity = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*>mpp;

    LRUCache(int capacity) {
        maxCapacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* toAdd){
        Node* temp = head -> next;
        toAdd -> next = temp;
        toAdd -> prev = head;
        temp -> prev = toAdd;
        head -> next = toAdd;
    }

    void delNode(Node* toDelete){
        Node* nextNode = toDelete -> next;
        Node* prevNode = toDelete -> prev;
        
        nextNode -> prev = prevNode;
        prevNode -> next = nextNode;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* toFront = mpp[key];
        delNode(toFront);
        addNode(toFront);
        return mpp[key] -> val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            mpp[key] -> val = value;
            Node* toFront = mpp[key];
            delNode(toFront);
            addNode(toFront);
            return;
        }
        if (mpp.size() == maxCapacity) {
            Node* toDelete = tail -> prev;
            mpp.erase(toDelete -> key);
            delNode(toDelete);
            delete(toDelete);
        }

        Node* toAdd = new Node(key, value);
        mpp[toAdd -> key] = toAdd;
        toAdd -> prev = head;
        toAdd -> next = head -> next;
        head -> next -> prev = toAdd;
        head -> next = toAdd;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */