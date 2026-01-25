class Solution {
public:
    using ll = long long;
    bool pythagoras(vector<int>& s){
        ll a = pow(s[0], 2);
        ll b = pow(s[1], 2);
        ll c = pow(s[2], 2);
        // cout << a << " " << b<<  " " <<c<< " ";
        // cout << endl;

        if (a + b == c) return true;
        return false;
    }

    void bfs(int src, vector<vector<int>>& adj, vector<int>& dist){
        dist[src] = 0;
        
        queue<int>q;
        q.push(src);

        while (!q.empty()){
            int node = q.front();
            int dis = dist[node];
            q.pop();

            for (auto& neigh : adj[node]){
                int adjNode = neigh;
                if (dist[adjNode] > dis + 1){
                    dist[adjNode] = dis+1;
                    q.push(adjNode);
                }
            }
        }

    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        vector<int>distX(n, 1e9), distY(n, 1e9), distZ(n, 1e9);

        for (auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(x, adj, distX);
        bfs(y, adj, distY);
        bfs(z, adj, distZ);
        
        int cnt = 0;
        for (int i = 0; i < n; i++){
            ll dx = distX[i];
            ll dy = distY[i];
            ll dz = distZ[i];
            
            if (dx >= 1e9 || dy >= 1e9 || dz >= 1e9) continue;
            vector<ll> s = {dx, dy, dz};
            
            sort(s.begin(), s.end());
            
            if ((s[0]*s[0]) + (s[1]*s[1]) == (s[2]*s[2])) cnt++;
        }

        return cnt;
    }
};