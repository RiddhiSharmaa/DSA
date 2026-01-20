class Solution {
public:
    int helper(int i, vector<int>& dp, vector<int>& cost){
        if (i >= dp.size()-1) return 0;
        if (dp[i] != -1) return dp[i];
        
        return dp[i] = cost[i] + min(helper(i+1, dp, cost), helper(i+2, dp, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);

        dp[n] = 0;
        helper(0, dp, cost);

        return min(dp[0], dp[1]);
    }
};