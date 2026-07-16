class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        vector<int>vis(n, 0);
        vector<vector<pair<int, int>>>adj(n);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int minCost = 0;
        pq.push({0, 0});

        while (!pq.empty()){
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();

            if (vis[n]) continue;
            minCost += d;
            vis[n] = 1;

            for (auto& p : adj[n]){
                int neigh = p.second;
                int dist = p.first;
                if (!vis[neigh]){
                    pq.push({dist, neigh});
                }
            }
        }

        return minCost;
    }
};