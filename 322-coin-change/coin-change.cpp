class Solution {
public:
    int dp[13][10001];
    int helper(int i, int target, vector<int>& coins){
        if (target == 0) return 0;
        if (i >= coins.size()) return 1e9;
        if (dp[i][target] != -1) return dp[i][target];

        int take = 1e8;
        if (coins[i] <= target){
            take = 1 + helper(i, target-coins[i], coins);
        }
        int notTake = helper(i+1, target, coins);
        return dp[i][target] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, amount, coins);
        return (ans >= 1e8) ? -1 : ans;
    }
};