class Solution {
public:
    int dp[301][5001];
    int helper(int i, int target, vector<int>& coins){
        if (target == 0) return 1;
        if (i >= coins.size()) return 0;
        if (dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if (coins[i] <= target){
            take = helper(i, target-coins[i], coins);
        }
        int notTake = helper(i+1, target, coins);
        return dp[i][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(0, amount, coins);
    }
};