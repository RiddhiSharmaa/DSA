class Solution {
public:
    bool helper(int i, int col, vector<int>& color, vector<vector<int>>& graph){
        color[i] = col;

        for (int adj : graph[i]){
            if (color[adj] != -1 && color[adj] == col) return false;
            if (color[adj] == -1) {
                color[adj] = col;
                if (!helper(adj, !col, color, graph)) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++){
            if (color[i] == -1){
                if (!helper(i, 0, color, graph)) return false;
            }
        }

        return true;
    }
};