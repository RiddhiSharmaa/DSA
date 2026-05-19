class Solution {
public:
    bool helper(int i, vector<int>& color, vector<vector<int>>& graph){
        queue<pair<int,int>>q;
        q.push({i, 0});
        color[i] = 0;

        while (!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int adj : graph[node]){
                int c = !col;
                if (color[adj] != -1 && color[adj] != c) return false;
                if (color[adj] == -1) {
                    color[adj] = c;
                    q.push({adj, c});
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++){
            if (color[i] == -1){
                if (!helper(i, color, graph)) return false;
            }
        }

        return true;
    }
};