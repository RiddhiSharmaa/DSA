class Solution {
public:
    void helper(int i, vector<int>& component, vector<int>& visited, vector<vector<int>>& adj){
        component.push_back(i);
        visited[i] = 1;
        for (auto& neighbour : adj[i]){
            if (!visited[neighbour]){
                helper(neighbour, component, visited, adj);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int>visited(n, 0);
        vector<vector<int>>adj(n);
        
        for (auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++){
            vector<int>component;
            bool flag = true;
            if (!visited[i]){
                helper(i, component, visited, adj);
                for (auto i : component){
                    if (adj[i].size() != component.size()-1){
                        flag = false;
                    }
                }
                if (flag) cnt++;
            }
        }

        return cnt;
    }
};