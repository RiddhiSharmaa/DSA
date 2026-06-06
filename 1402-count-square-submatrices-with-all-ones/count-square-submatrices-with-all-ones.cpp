class Solution {
public:
    int cnt = 0;
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int left = helper(i-1, j, dp, matrix);
        int up = helper(i, j-1, dp, matrix);
        int diag = helper(i-1, j-1, dp, matrix);

        if (matrix[i][j] == 1){
            dp[i][j] = 1 + min({left, up, diag});
            cnt += dp[i][j];
            return dp[i][j];
        }

        return dp[i][j] = 0;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                helper(i, j, dp, matrix);
            }
        }

        return cnt;
    }
};