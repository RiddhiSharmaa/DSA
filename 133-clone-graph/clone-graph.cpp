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
        unordered_map<Node*, Node*>mpp;
        queue<Node*>q;
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();
            if (curr && mpp.find(curr) == mpp.end()) mpp[curr] = new Node(curr -> val);
            else continue;

            vector<Node*>&neigh = curr -> neighbors;
            for (int i = 0; i < neigh.size(); i++){
                q.push(neigh[i]);
            }
        }

        q.push(node);
        vector<int>vis(mpp.size()+1);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();
            if (!curr) continue;
            if (vis[curr -> val]) continue;
            vis[curr -> val] = 1;
            vector<Node*>&neigh = curr -> neighbors;
            for (int i = 0; i < neigh.size(); i++){
                mpp[curr] -> neighbors.push_back(mpp[neigh[i]]);
                q.push(neigh[i]);
            }
        }

        return mpp[node];
    }
};