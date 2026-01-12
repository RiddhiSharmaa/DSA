class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1, 1e9);
        vector<vector<pair<int, int>>>adj(n+1);

        for (auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>>pq;

        int minTime = 0;
        time[k] = 0;
        pq.push({0, k});

        while (!pq.empty()){
            int node = pq.top().second;
            int currTime = pq.top().first;
            pq.pop();

            for (auto& neigh : adj[node]){
                int adjNode = neigh.first;
                int adjWt = neigh.second;

                if (currTime + adjWt < time[adjNode]){
                    time[adjNode] = currTime + adjWt;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i < time.size(); i++){
            ans = max(ans, time[i]);
        }

        return (ans == 1e9) ? -1 : ans;
    }
};