class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     dp[n]
    // }
    int helper(int i, int j, vector<vector<int>>& dp){
        if (i >= dp.size() || j >= dp[0].size()) return 0;
        if (i == dp.size() - 1 && j == dp[0].size() - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int right = helper(i+1, j, dp);
        int down = helper(i, j+1, dp);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));

        return helper(0, 0, dp);
    }
};