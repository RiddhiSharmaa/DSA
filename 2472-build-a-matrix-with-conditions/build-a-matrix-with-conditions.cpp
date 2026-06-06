class Solution {
public:
    vector<int>topoSort(int& k, vector<vector<int>>& conditions, 
    vector<vector<int>>& adj){
        vector<int>ind(k+1, 0);
        vector<int>topo;

        for (auto& c : conditions){
            ind[c[1]]++;
        }

        queue<int>q;
        for (int i = 1; i < ind.size(); i++){
            if (ind[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto& neigh : adj[node]){
                ind[neigh]--;
                if (ind[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return topo;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k, vector<int>(k, 0));
        vector<vector<int>>rowGraph(k+1), colGraph(k+1);
    
        for (auto& r : rowConditions){
            rowGraph[r[0]].push_back(r[1]);
        }

        for (auto& c : colConditions){
            colGraph[c[0]].push_back(c[1]);
        }

        vector<int>topoRow = topoSort(k, rowConditions, rowGraph);
        vector<int>topoCol = topoSort(k, colConditions, colGraph);

        if (topoRow.size() != k || topoCol.size() != k) return {};

        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                if (topoRow[i] == topoCol[j]){
                    ans[i][j] = topoCol[j];
                }
            }
        }
        
        return ans;
    }
};