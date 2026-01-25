class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        for (int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for (int j = 1; j <= amount; j++){
            dp[n][j] = 1e9;
        }

        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j <= amount; j++){
                int notPick = dp[i+1][j];
                int pick = 1e9;
                if (j- coins[i] >= 0) pick = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(pick, notPick);
            }
        }

        int ans = dp[0][amount];

        return ans >= 1e9 ? -1 : ans;
    }

    // int helper(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
    //     if (target == 0) return 0;
    //     if (target < 0) return 1e9;
    //     if (i >= nums.size()) return 1e9;
    //     if (dp[i][target] != -1) return dp[i][target];

    //     int notPick = helper(i+1, target, nums, dp);
    //     int pick = 1e9;
    //     if (target - nums[i] >= 0){
    //         pick = 1 + helper(i, target - nums[i], nums, dp);
    //     }
        
    //     return dp[i][target] = min(pick, notPick);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n, vector<int>(amount+1, -1));

    //     int ans = helper(0, amount, coins, dp);

    //     return (ans == 1e9) ? -1 : ans;
    // }
};