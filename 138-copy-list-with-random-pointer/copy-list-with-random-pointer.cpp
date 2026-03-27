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
        Node* temp = head;

        while (temp != nullptr){
            Node* tempNode = new Node(temp -> val);
            tempNode -> next = temp -> next;
            temp -> next = tempNode;
            temp = tempNode -> next;
        }

        temp = head;
        Node* ans = temp -> next;
        while (temp != nullptr){
            Node* nextNode = temp -> next;
            nextNode -> random = (temp -> random) ? temp -> random -> next : nullptr;
            temp = temp -> next -> next;
        }

        temp = head;
        while (temp){
            Node* nextNode = temp -> next;
            temp -> next = nextNode -> next;
            nextNode -> next = (nextNode -> next) ? nextNode -> next -> next : nullptr;
            temp = temp -> next;
        }
        return ans;
    }
};