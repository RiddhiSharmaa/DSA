class DSU{
public:
    vector<int>parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void updateRank(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if (px == py) return;
        if (rank[px] > rank[py]){
            rank[px]++;
            parent[py] = px;
        } else if (rank[py] > rank[px]){
            rank[py]++;
            parent[px] = py;
        } else {
            parent[px] = py;
        }
    }

};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        int minCost = 0;

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                pq.push({dist, {i, j}});
            }
        }

        DSU pts(n);
        int edges = 0;
        while (!pq.empty() && edges < n){
            int d = pq.top().first;
            int n1 = pq.top().second.first;
            int n2 = pq.top().second.second;
            pq.pop();

            if (pts.findParent(n1) == pts.findParent(n2)) continue;
            else {
                minCost += d;
                pts.updateRank(n1, n2);
                edges++;
            }
        }
        
        return minCost;
    }
};