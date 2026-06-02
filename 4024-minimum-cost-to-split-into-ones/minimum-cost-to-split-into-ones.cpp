class Solution {
public:
    int helper(int i, vector<int>& dp){
        if (i == 1) return 0;
        if (i == 2) return 1;
        if (dp[i] != -1) return dp[i];

        int cost = 0;
        if (i % 2 != 0){
            cost = i-1 + minCost(i-1);
        } else {
            cost = i/2 * i/2 + 2 * minCost(i/2);
        }

        return dp[i] = cost;
    }

    int minCost(int n) {
        vector<int>dp(n+1, -1);
        return helper(n, dp);
    }
};