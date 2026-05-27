class Solution {
public:
    int helper(int i, vector<int>& dp){
        if (i <= 2) return i;
        if (dp[i] != -1) return dp[i];

        return dp[i] = helper(i-1, dp) + helper(i-2, dp);
    }
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        vector<int>dp(n+1, -1);
        return helper(n, dp);
    }
};