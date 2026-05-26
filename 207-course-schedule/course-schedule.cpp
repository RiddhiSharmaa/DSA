class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);

        for (auto& e : prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int>q;
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0) q.push(i);
        }

        if (q.empty()) return false;

        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (auto& neighbour : adj[node]){
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] > 0) return false;
        }

        return true;
    }
};