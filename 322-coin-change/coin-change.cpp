class Solution {
public:
    int dp[13][10001];
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));

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
                if (j - coins[i] >= 0){ 
                    pick = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(pick, notPick);
            }
        }

        return dp[0][amount] >= 1e9 ? -1 : dp[0][amount];
    }
};