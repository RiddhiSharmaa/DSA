class Solution {
public:
    bool helper(int i, vector<int>& visited, unordered_map<int,int>& mpp, 
    vector<vector<int>>& graph){
        queue<pair<int,int>>q;
        q.push({i, 0});

        while (!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int adj : graph[node]){
                int c = !col;
                if (visited[adj] && mpp[adj] != c && mpp[adj] != node) return false;
                if (!visited[adj]) {
                    mpp[adj] = c;
                    visited[adj] = 1;
                    q.push({adj, c});
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int>mpp;
        vector<int>visited(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++){
            for (auto v : graph[i]){
                mpp[i] = v;
            }
        }

        for (int i = 0; i < graph.size(); i++){
            if (!visited[i]){
                if (!helper(i, visited, mpp, graph)) return false;
            }
        }

        return true;
    }
};