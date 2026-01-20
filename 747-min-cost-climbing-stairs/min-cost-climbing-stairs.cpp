class Solution {
public:
    int helper(int n, vector<int>& dp, vector<int>& cost){
        if (n >= dp.size()-1) return 0;
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = min(cost[n] + helper(n+1, dp, cost), cost[n] + helper(n+2, dp, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        dp[n] = 0;
        helper(0, dp, cost);
        return min(dp[0], dp[1]);
    }
};