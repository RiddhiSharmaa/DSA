class Solution {
public: 
    void helper(int i, int j, int &cnt, vector<int>& row, vector<int>& col, 
    vector<vector<char>>& grid){
        grid[i][j] = '2';

        for (int k = 0; k < row.size(); k++){
            int r = i + row[k];
            int c = j + col[k];

            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && 
            grid[r][c] == '1'){
                helper(r, c, cnt, row, col, grid);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<int>row = {-1, 0, 1, 0};
        vector<int>col = {0, 1, 0, -1};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1'){
                    cnt++;
                    helper(i, j, cnt, row, col, grid);
                }
            }
        }

        return cnt;
    }
};