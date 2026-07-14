class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1, 1e9);
        vector<vector<pair<int, int>>>adj(n+1);
        int minTime = INT_MIN;

        for (auto& t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;
        pq.push({0, k});
        time[k] = 0;

        while (!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (t > time[node]) continue;
            minTime = max(minTime, t);

            for (auto& p : adj[node]){
                int adjNode = p.first;
                int adjTime = p.second;
                if (adjTime + t < time[adjNode]){
                    time[adjNode] = adjTime + t;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }

        for (int i = 1; i <= n; i++){
            if (time[i] == 1e9) return -1;
        }
        return minTime;
    }
};