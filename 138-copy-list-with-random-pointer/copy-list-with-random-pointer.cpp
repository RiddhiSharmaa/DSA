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
        Node* temp = head;
        unordered_map<Node*, Node*>mpp;

        while (temp){
            Node* newNode = new Node(temp -> val);
            mpp[temp] = newNode;
            temp = temp -> next;
        }

        for (auto& [original, copy] : mpp){
            copy -> next = original -> next ? mpp[original -> next] : nullptr;
            copy -> random = original -> random ? mpp[original -> random] : nullptr;
        }

        return mpp[head];
    }
};