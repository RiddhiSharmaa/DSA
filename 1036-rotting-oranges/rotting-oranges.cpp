class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, pair<int, int>>>q;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        int minTime = 0;
        while (!q.empty()){
            int t = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            minTime = max(minTime, t);

            for (int i = 0; i < 4; i++){
                int r = x + row[i];
                int c = y + col[i];
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1){
                    q.push({t+1, {r, c}});
                    grid[r][c] = 2;
                    fresh--;
                }
            }
        }

        return (fresh == 0) ? minTime : -1;
    }
};