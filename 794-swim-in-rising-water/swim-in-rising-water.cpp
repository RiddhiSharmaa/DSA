class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>time(n, vector<int>(n, 1e9));
        vector<vector<int>>visited(n, vector<int>(n, 0));
        priority_queue<P, vector<P>, greater<P>>pq;

        pq.push({grid[0][0], {0, 0}});
        time[0][0] = grid[0][0];

        vector<int>rows =  {-1, 0, 1, 0};
        vector<int>cols = {0, 1, 0, -1};

        while (!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int t = pq.top().first;
            pq.pop();

            if (t > time[row][col]) continue;
            if (row == n-1 && col == n-1) return t;
            visited[row][col] = 1;
            
            for (int i = 0; i < 4; i++){
                int r = row + rows[i];
                int c = col + cols[i];

                if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]){
                    int newTime = max(t, grid[r][c]);
                    if (newTime < time[r][c]) {
                        time[r][c] = newTime;
                        pq.push({newTime, {r, c}});
                    }

                }
            }
        }

        return -1;
    }
};