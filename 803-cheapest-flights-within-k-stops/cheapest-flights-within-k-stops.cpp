class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        vector<int>dist(n, 1e9);

        for (auto& f : flights){
            int u = f[0];
            int v = f[1];
            int w = f[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>>pq;
        pq.push({0, {0, src}});
        dist[src] = 0;

        while (!pq.empty()){
            int stops = pq.front().first;
            int price = pq.front().second.first;
            int node = pq.front().second.second;
            pq.pop();

            for (auto& n : adj[node]){
                int adjNode = n.first;
                int adjPrice = n.second;

                if (stops+1 <= k+1 && adjPrice + price < dist[adjNode]){
                    dist[adjNode] = adjPrice + price;
                    pq.push({stops+1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};