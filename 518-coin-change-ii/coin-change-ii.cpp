class Solution {
public:
    int cnt = 0;
    int helper(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if (target == 0) {
            cnt++;
            return 1;
        }
        if (i >= coins.size()) return 0;
        if (dp[i][target] != -1) return dp[i][target];

        int notPick = helper(i+1, target, coins, dp);
        int pick = 0;
        if (target - coins[i] >= 0){
            pick = helper(i, target - coins[i], coins, dp);
        }

        return dp[i][target] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        return helper(0, amount, coins, dp);
    }
};