class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        
        for (int i = 0; i <= m; i++){
            dp[i][n] = 0;
        }

        for (int j = 0; j <= n; j++){
            dp[m][j] = 0;
        }

        for (int i = m-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                if (i == m-1 && j == n-1){
                    dp[i][j] = 1;
                    continue;
                }
                int right = dp[i+1][j];
                int down = dp[i][j+1];

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }

    // int helper(int i, int j, vector<vector<int>>& dp){
    //     if (i >= dp.size() || j >= dp[0].size()) return 0;
    //     if (i == dp.size() - 1 && j == dp[0].size() - 1) return 1;
    //     if (dp[i][j] != -1) return dp[i][j];

    //     int right = helper(i+1, j, dp);
    //     int down = helper(i, j+1, dp);

    //     return dp[i][j] = right + down;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m, vector<int>(n, -1));

    //     return helper(0, 0, dp);
    // }
};