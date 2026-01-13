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

        queue<T> q; 

        q.push({0, 0, src}); // stops, price, node
        prices[src] = 0;

        while (!q.empty()){ // O(E)
            int price = get<1>(q.front());
            int stops = get<0>(q.front());
            int node = get<2>(q.front());
            q.pop(); // O(1)

            for (auto& neigh : adj[node]){ // O(E)
                int adjNode = neigh.first;
                int adjWt = neigh.second;
                int nextStop = stops + 1;
                if (nextStop <= k+1 && price + adjWt < prices[adjNode]){
                    prices[adjNode] = price + adjWt;
                    q.push({stops+1, prices[adjNode], adjNode}); // O(1)
                }

            }
        }

        return (prices[dst] == 1e9) ? -1 : prices[dst];
    }

    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<int>prices(n, 1e9);
    //     vector<vector<pair<int, int>>>adj(n);

    //     for (auto& edge : flights){
    //         int u = edge[0];
    //         int v = edge[1];
    //         int w = edge[2];
    //         adj[u].push_back({v, w});
    //     }

    //     priority_queue<T, vector<T>, greater<T>> pq; 

    //     pq.push({0, 0, src}); // stops, price, node
    //     prices[src] = 0;

    //     while (!pq.empty()){ // O(E)
    //         int price = get<1>(pq.top());
    //         int stops = get<0>(pq.top());
    //         int node = get<2>(pq.top());
    //         pq.pop(); // O(logV)

    //         for (auto& neigh : adj[node]){ // O(E)
    //             int adjNode = neigh.first;
    //             int adjWt = neigh.second;
    //             int nextStop = stops + 1;
    //             if (nextStop <= k+1 && price + adjWt < prices[adjNode]){
    //                 prices[adjNode] = price + adjWt;
    //                 pq.push({stops+1, prices[adjNode], adjNode}); // O(logV)
    //             }

    //         }
    //     }

    //     return (prices[dst] == 1e9) ? -1 : prices[dst];
    // }
};