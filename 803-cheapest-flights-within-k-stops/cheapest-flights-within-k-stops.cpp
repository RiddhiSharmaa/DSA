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

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, src}});
        dist[src] = 0;

        while (!pq.empty()){
            int stops = pq.top().first;
            int price = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if (stops > k) continue;

            for (auto& n : adj[node]){
                int adjNode = n.first;
                int adjPrice = n.second;

                if (adjPrice + price < dist[adjNode]){
                    dist[adjNode] = adjPrice + price;
                    pq.push({stops+1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};