class Solution {
public:
    // By Bellman Ford
    int bellmanFord(int node, int n, vector<vector<int>>& edges, 
    int &distanceThreshold){
        int cnt = 0;
        vector<int>dist(n, 1e9);
        dist[node] = 0;

        for (int i = 0; i < n-1; i++){
            for (auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != 1e9 && w + dist[u] < dist[v]){
                    dist[v] = w + dist[u];
                }
                
                // belman ford is only for directed graphs, hence for undirected 
                // we have to make a - b => (a -> b) && (b -> a)
                if (dist[v] != 1e9 && w + dist[v] < dist[u]){
                    dist[u] = w + dist[v]; 
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (dist[i] <= distanceThreshold) cnt++;
        }

        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int minCnt = distanceThreshold;
        int ans = 0;

        for (int i = 0; i < n; i++){
            int getCnt = bellmanFord(i, n, edges, distanceThreshold);
            if (getCnt <= minCnt){
                minCnt = getCnt;
                ans = i;
            }
        }

        return ans;
    }
    // By Floyd Warshall
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<vector<int>>dist(n, vector<int>(n,1e9));
    //     int cnt = INT_MAX;
    //     int ans = 0;

    //     for (auto& edge : edges){
    //         int u = edge[0];
    //         int v = edge[1];
    //         int w = edge[2];
    //         dist[u][v] = w;
    //         dist[v][u] = w;
    //     }

    //     for (int i = 0; i < n; i++){
    //         for (int j = 0; j < n; j++){
    //             if (i == j) dist[i][j] = 0;
    //         }
    //     }

    //     for (int via = 0; via < n; via++){
    //         for (int i = 0; i < n; i++){
    //             for (int j = 0; j < n; j++){
    //                 dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
    //             }
    //         }
    //     }

    //     for (int i = 0; i < n; i++){
    //         int rowWiseCount = 0;
    //         for (int j = 0; j < n; j++){
    //             if (dist[i][j] <= distanceThreshold){
    //                 rowWiseCount++;
    //             }
    //         }
    //         if (rowWiseCount <= cnt){
    //             cnt = rowWiseCount;
    //             ans = i;
    //         }
    //     }

    //     return ans;
    // }

    // By Djisktra
    // int djikstra(int node, vector<vector<pair<int, int>>>& adj, 
    // int &distanceThreshold){
    //     vector<int>dist(adj.size(), 1e9);
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, 
    //     greater<pair<int,int>>>pq;

    //     pq.push({0, node});
    //     dist[node] = 0;

    //     while (!pq.empty()){
    //         int node = pq.top().second;
    //         int d = pq.top().first;
    //         pq.pop();

    //         for (auto& neigh : adj[node]){
    //             int adjNode = neigh.first;
    //             int adjWt = neigh.second;

    //             if (adjWt + d < dist[adjNode]){
    //                 dist[adjNode] = adjWt + d;
    //                 pq.push({dist[adjNode], adjNode});
    //             }
    //         }
    //     }

    //     int count = 0;

    //     for (int i = 0; i < adj.size(); i++){
    //         if (dist[i] <= distanceThreshold) count++;
    //     }

    //     return count;
    // }
    // int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    //     vector<vector<pair<int, int>>> adj(n+1);
    //     int cnt = distanceThreshold;
    //     int ans = 0;

    //     for (auto& edge : edges){
    //         int u = edge[0];
    //         int v = edge[1];
    //         int w = edge[2];

    //         adj[u].push_back({v, w});
    //         adj[v].push_back({u, w});
    //     }

    //     for (int i = 0; i < n; i++){
    //         int getCnt = djikstra(i, adj, distanceThreshold);
    //         if (getCnt <= cnt){
    //             cnt = getCnt;
    //             ans = i;
    //         }
    //     }

    //     return ans;
    // }
};