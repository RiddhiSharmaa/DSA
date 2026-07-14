class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int vis[301][301];
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>>q;
        q.push({i, j});
        vis[i][j] = 1;

        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++){
                int r = dr[k] + x;
                int c = dc[k] + y;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                grid[r][c] == '1' && !vis[r][c]){
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(vis, 0, sizeof(vis));
        int cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};