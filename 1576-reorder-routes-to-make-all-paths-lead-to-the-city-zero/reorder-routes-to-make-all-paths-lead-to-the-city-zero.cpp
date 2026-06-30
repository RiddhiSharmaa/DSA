class Solution {
public:
    void dfs(int node, int& cnt, vector<int>& visited, 
    vector<vector<pair<int, int>>>& adj){
        visited[node] = 1;

        for (auto& p : adj[node]){
            if (!visited[p.first]){
                cnt += p.second;
                dfs(p.first, cnt, visited, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adj(n);
        vector<int>visited(n, 0);
        int cnt = 0;

        for (auto& c : connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        dfs(0, cnt, visited, adj);

        return cnt;
    }
};