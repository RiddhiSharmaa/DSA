class DisjointSet {
public:
    vector<int>parent;
    vector<int>size;

    DisjointSet(int V){
        parent.resize(V, 0);
        size.resize(V, 1);
        for (int i = 0; i < V; i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]); // path compression
    }

    void UnionBySize(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else if (size[px] <= size[py]){
            parent[px] = py;
            size[px] += size[py];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size()+1);
        vector<int>ans;
        for (auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            if (ds.findParent(u) != ds.findParent(v)){
                ds.UnionBySize(u, v);
            } else {
                ans = edge;
            }
        }

        return ans;
    }
};