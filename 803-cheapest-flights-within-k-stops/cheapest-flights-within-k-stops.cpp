class Solution {
public:
    typedef tuple<int, int, int> T;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n, 1e9);
        vector<vector<pair<int, int>>>adj(n);

        for (auto& edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<T, vector<T>, greater<T>> pq; 

        pq.push({0, 0, src}); // stops, price, node
        prices[src] = 0;
        int ans = INT_MAX;

        while (!pq.empty()){
            int price = get<1>(pq.top());
            int stops = get<0>(pq.top());
            int node = get<2>(pq.top());
            pq.pop();

            if (stops > k+1) continue;
            if (node == dst && stops <= k+1) ans = min(ans, price);

            for (auto& neigh : adj[node]){
                int adjNode = neigh.first;
                int adjWt = neigh.second;
                if (price + adjWt < prices[adjNode]){
                    prices[adjNode] = price + adjWt;
                    pq.push({stops+1, prices[adjNode], adjNode});
                }

            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};