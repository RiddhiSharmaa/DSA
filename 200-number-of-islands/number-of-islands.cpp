class Solution {
public:
    void dfs(int i, int j, vector<int>& row, vector<int>& col, 
    vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[i][j] = 1;

        for (int k = 0; k < 4; k++){
            int r = row[k] + i;
            int c = col[k] + j;
            if (r < grid.size() && r >= 0 && c >= 0 && c < grid[0].size() &&
            !visited[r][c] && grid[r][c] == '1'){
                dfs(r, c, row, col, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};

        int cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j , row, col, visited, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};