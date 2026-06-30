class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>>adj(n);
        vector<double>dist(n, 0.0);
        priority_queue<pair<double, int>>pq;

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({succProb[i], v});
            adj[v].push_back({succProb[i], u});
        }

        pq.push({1.0, start_node});
        dist[start_node] = 0.0;

        while (!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            if (prob < dist[node]) continue;
            if (node == end_node) return prob;

            for (auto& p : adj[node]){
                int adjNode = p.second;
                double adjProb = p.first;
                if (adjProb * prob > dist[adjNode]){
                    dist[adjNode] = adjProb * prob;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return 0.0;
    }
};