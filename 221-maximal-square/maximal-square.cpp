class Solution {
public:
    int maxi = 0;
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<char>>& matrix){
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int right = helper(i-1, j, dp, matrix);
        int down = helper(i, j-1, dp, matrix);
        int diag = helper(i-1, j-1, dp, matrix);

        if (matrix[i][j] == '1'){
            dp[i][j] = 1 + min({right, down, diag});
            return dp[i][j];
        }

        return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int a = helper(i, j, dp, matrix);
                maxi = max(maxi, a);
            }
        }
        
        return maxi * maxi;
    }
};