/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*>mpp;
        queue<Node*>q;
        q.push(node);

        Node* head = new Node(node -> val);
        mpp[1] = head;

        Node* neighNew;
        while (!q.empty()){
            Node* temp = q.front();
            q.pop();

            Node* curr = mpp[temp -> val];

            for (auto& neigh : temp -> neighbors){
                if (mpp.find(neigh -> val) == mpp.end()){
                    neighNew = new Node(neigh -> val);
                    mpp[neigh -> val] = neighNew;
                    q.push(neigh);
                } else {
                    neighNew = mpp[neigh -> val];
                }

                curr -> neighbors.push_back(neighNew);
            }
        }

        return head;
    }
};