class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;

        pq.push({grid[0][0], {0, 0}});
        time[0][0] = grid[0][0];
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};

        while (!pq.empty()){
            auto node = pq.top().second;
            int t = pq.top().first;
            pq.pop();

            if (t > time[node.first][node.second]) continue;

            if (node.first == n-1 && node.second == n-1) return t;

            for (int i = 0; i < 4; i++){
                int r = row[i] + node.first;
                int c = col[i] + node.second;
               
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && 
                max(t, grid[r][c]) < time[r][c]){
                    time[r][c] = max(t, grid[r][c]);
                    pq.push({time[r][c], {r, c}});
                }                
            }
            
        }

        return -1;
    }
};