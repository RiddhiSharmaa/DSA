class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        int n = prerequisites.size();
        int m = prerequisites[0].size();
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        int cnt = n;

        for (auto& e : prerequisites){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
            inDegree[v]++;
            if (u == v) return false;
        }

        queue<int>q;

        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0) q.push(i);
        }

        if (q.empty()) return false;
        while (!q.empty()){
            int course = q.front();
            q.pop();

            for (auto& adjNode : adj[course]){
                inDegree[adjNode]--;
                cnt--;
                if (inDegree[adjNode] == 0) q.push(adjNode);
            }
        }

        return cnt == 0;
    }
};