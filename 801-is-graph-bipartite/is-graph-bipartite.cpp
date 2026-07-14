class Solution {
public:
    bool dfs(int node, int color, vector<int>& col, vector<vector<int>>& graph){
        col[node] = color;

        for (auto& n : graph[node]){
            if (col[n] == -1){
                if (!dfs(n, !color, col, graph)) return false;
            } else if (col[n] == color){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n, -1);

        for (int i = 0; i < n; i++){
            if (col[i] == -1){
                if (!dfs(i, 0, col, graph)) return false;
            }
        }

        return true;
    }
};