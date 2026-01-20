class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++){
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }

        return dp[n];
    }
    // int helper(int i, vector<int>& dp, vector<int>& cost){
    //     if (i >= dp.size()-1) return 0;
    //     if (dp[i] != -1) return dp[i];
        
    //     return dp[i] = cost[i] + min(helper(i+1, dp, cost), helper(i+2, dp, cost));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int>dp(n+1, -1);

    //     dp[n] = 0;
    //     helper(0, dp, cost);

    //     return min(dp[0], dp[1]);
    // }
};