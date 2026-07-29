class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>timeArr(n, vector<int>(m, 1e9));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    timeArr[i][j] = 0;
                }
            }
        }

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        int minTime = 0;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            grid[x][y] = 2;

            for (int i = 0; i < 4; i++){
                int r = x + row[i];
                int c = y + col[i];
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && 
                timeArr[r][c] > timeArr[x][y]+1){
                    timeArr[r][c] = timeArr[x][y]+1;
                    q.push({r, c});
                }
            }
        }


        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) return -1;
                else if (grid[i][j] == 2) minTime = max(minTime, timeArr[i][j]);
            }
        }

        return minTime;
    }
};