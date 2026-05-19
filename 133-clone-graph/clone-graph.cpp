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

        Node* head; 
        Node* neighNew;
        while (!q.empty()){
            int n = q.front() -> val;
            Node* temp = q.front();
            q.pop();

            if (mpp.find(n) == mpp.end()){
                head = new Node(n);
                mpp[n] = head;
            } else {
                head = mpp[n];
            }

            for (auto& neigh : temp -> neighbors){
                if (mpp.find(neigh -> val) == mpp.end()){
                    neighNew = new Node(neigh -> val);
                    mpp[neigh -> val] = neighNew;
                    q.push(neigh);
                } else {
                    neighNew = mpp[neigh -> val];
                }
                head -> neighbors.push_back(neighNew);
            }
        }

        return mpp[1];
    }
};