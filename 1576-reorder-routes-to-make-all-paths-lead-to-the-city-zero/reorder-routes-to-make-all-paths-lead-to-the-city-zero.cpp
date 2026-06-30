class Solution {
public:
    void dfs(int node, int& cnt, vector<int>& visited, vector<vector<int>>& adj){
        visited[node] = 1;

        for (auto& p : adj[node]){
            int n = abs(p);
            if (!visited[n]){
                if (p < 0) cnt++;
                dfs(n, cnt, visited, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<int>visited(n, 0);
        int cnt = 0;

        for (auto& c : connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(-v);
            adj[v].push_back(u);
        }
        
        dfs(0, cnt, visited, adj);

        return cnt;
    }
};