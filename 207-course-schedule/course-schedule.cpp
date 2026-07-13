class Solution {
public:
    bool helper(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for (auto& neigh : adj[node]){
            if (vis[neigh] == 0){
                if (helper(neigh, vis, adj)) return true;
            } else if (vis[neigh] == 1){
                return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses);

        for (auto& p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++){
            if (vis[i] == 0){
                if (helper(i, vis, adj)) return false;
            }
        }

        return true;
    }
};