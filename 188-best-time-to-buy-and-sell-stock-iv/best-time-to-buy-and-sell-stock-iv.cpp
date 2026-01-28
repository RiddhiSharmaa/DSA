class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j < 2; j++){
                for (int tr = k-1; tr >= 0; tr--){
                    int profit = 0;
                    if (j == 1){
                        profit = max(-prices[i] + dp[i+1][!j][tr],
                                    0 + dp[i+1][j][tr]);
                    } else {
                        profit = max(prices[i] + dp[i+1][!j][tr+1],
                                    0 + dp[i+1][j][tr]);
                    }
                    dp[i][j][tr] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};