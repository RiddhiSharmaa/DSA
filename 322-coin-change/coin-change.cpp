class Solution {
public:
    int dp[13][10001];

    int helper(int i, vector<int>& coins, int target){
        if (target == 0) return 0;
        if (i >= coins.size()) return 1e9;
        if (dp[i][target] != -1) return dp[i][target];

        int notPick = helper(i+1, coins, target);
        int pick = 1e9;
        if (target - coins[i] >= 0){ 
            pick = 1 + helper(i, coins, target - coins[i]);
        }

        return dp[i][target] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, coins, amount);

        return (ans >= 1e9) ? -1 : ans;
    }
};