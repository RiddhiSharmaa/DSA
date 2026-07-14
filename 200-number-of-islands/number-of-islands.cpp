class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int vis[301][301];
    void dfs(int i, int j, vector<vector<char>>& grid){
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++){
            int r = dr[k] + i;
            int c = dc[k] + j;
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
            grid[r][c] == '1' && !vis[r][c]){
                dfs(r, c, grid);
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
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};