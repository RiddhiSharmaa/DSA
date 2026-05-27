class Solution {
public:
    int helper(int i, int amount, vector<vector<int>>& dp, vector<int>& coins){
        if (amount == 0) return 0;
        if (i >= coins.size()) return 1e9;
        if (amount < 0) return 1e9;

        if (dp[i][amount] != -1) return dp[i][amount];


        int notPick = helper(i+1, amount, dp, coins);
        int pick = 1e9;
        if (amount - coins[i] >= 0){
            pick = 1 + helper(i, amount - coins[i], dp, coins);
        }

        return dp[i][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        int ans = helper(0, amount, dp, coins);

        return ans >= 1e9 ? -1 : ans;
    }
};