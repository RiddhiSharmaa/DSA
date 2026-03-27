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
        if (!head) return nullptr;

        unordered_map<Node*, Node*>mpp;
        Node* temp = head;

        while (temp != nullptr){
            Node* tempNode = new Node(temp -> val);
            mpp[temp] = tempNode;
            temp = temp -> next;
        }

        temp = head;
        while (temp != nullptr){
            mpp[temp] -> next = mpp[temp -> next];
            mpp[temp] -> random = mpp[temp -> random];
            temp = temp -> next;
        }

        return mpp[head];
    }
};