class Solution {
public:
    const int MOD = 1000000007;
    int countPaths(int i, int j, int x, vector<vector<vector<int>>>& dp, 
    vector<vector<int>>& grid, int& k){
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            if (x == k) return 1;
            return 0;
        }

        if (dp[i][j][x] != -1) return dp[i][j][x];

        int right = 0, down = 0;
        if (j+1 < grid[0].size()){
            right = countPaths(i, j+1, x ^ grid[i][j+1], dp, grid, k);
        }
        if (i+1 < grid.size()){
            down = countPaths(i+1, j, x ^ grid[i+1][j], dp, grid, k);
        }

        return dp[i][j][x] = (right + down)%MOD;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(16, -1)));

        int x = grid[0][0];
        int ans = (countPaths(0, 0, x, dp, grid, k)) % MOD;

        return ans;
    }
};