class Solution {
public:
    int helper(int i, vector<int>& cost, vector<int>& dp){
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = 0, notPick = 0;
        pick = cost[i] + helper(i+1, cost, dp);
        notPick = cost[i] + helper(i+2, cost, dp);
        // notPick = helper(i+1, cost, dp);

        return dp[i] = min(pick, notPick);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int minCost = 0;
        int n = cost.size();
        vector<int>dp(n, -1);

        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};