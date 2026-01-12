class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        vector<int>visited(points.size(), 0);

        for (int i = 0; i < points.size(); i++){
            for (int j = i+1; j < points.size(); j++){
                int Mdist = abs(points[i][0] - points[j][0]) +
                abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, Mdist});
                adj[j].push_back({i, Mdist});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;

        pq.push({0, 0});

        int ans = 0;

        while (!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (visited[node]) continue;

            visited[node] = 1;
            ans += dist;

            for (auto& neigh : adj[node]){
                int adjNode = neigh.first;
                int adjWt = neigh.second;
                if (!visited[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return ans;
    }
};